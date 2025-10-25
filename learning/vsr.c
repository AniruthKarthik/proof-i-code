#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct
{
	char regNo[16];
	char model[32];
	int kmRun;
	float amount;
} Service;

void getinput(Service **veh, int n)
{
	if (n == 0)
	{
		*veh = malloc(sizeof(Service));
	}
	else
	{
		*veh = realloc(*veh, sizeof(Service) * (n + 1));
	}

	if (*veh == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}

	printf("Enter regno: ");
	scanf("%15s", (*veh)[n].regNo);

	printf("Enter model: ");
	scanf("%31s", (*veh)[n].model);

	printf("Enter km: ");
	scanf("%d", &(*veh)[n].kmRun);

	printf("Enter amount: ");
	scanf("%f", &(*veh)[n].amount);
}

Service *mostexp(Service *veh, int n)
{
	if (veh == NULL || n == 0)
		return NULL;

	Service *maxs = &veh[0];
	float maxx = veh[0].amount;

	for (int i = 1; i < n; i++)
	{
		if (veh[i].amount > maxx)
		{
			maxx = veh[i].amount;
			maxs = &veh[i];
		}
	}
	return maxs;
}

// 3. Save records with kmRun > km to binary file
int savekm(const Service *s, int n, int km, const char *fname)
{
	FILE *fp = fopen(fname, "wb");
	if (fp == NULL)
	{
		perror("Error opening file for writing");
		return -1;
	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i].kmRun > km)
		{
			if (fwrite(&s[i], sizeof(Service), 1, fp) == 1)
				count++;
			else
			{
				perror("Error writing record");
				fclose(fp);
				return -1;
			}
		}
	}

	fclose(fp);
	return count;
}

int lloadf(Service **s, const char *fn)
{
	FILE *fp = fopen(fn, "rb");
	if (!fp)
	{
		perror("Error opening file");
		return -1;
	}

	fseek(fp, 0, SEEK_END);
	long fs = ftell(fp);
	rewind(fp);

	if (fs <= 0)
	{
		printf("File is empty or invalid.\n");
		fclose(fp);
		return 0;
	}

	int recc = fs / sizeof(Service);
	*s = malloc(recc * sizeof(Service));
	if (!*s)
	{
		perror("Memory allocation failed");
		fclose(fp);
		return -1;
	}

	fread(*s, sizeof(Service), recc, fp);
	fclose(fp);

	return recc;
}

// Helper to print a single service record
void printService(const Service *s)
{
	printf("RegNo: %-10s  Model: %-10s  Km: %-6d  Amount: %.2f\n", s->regNo,
	       s->model, s->kmRun, s->amount);
}

int main()
{
	int n = 0;
	Service *veh = NULL;

	int flag = 1;
	while (flag)
	{
		printf("\n1. Enter records\n2. Most expensive\n3. Save > km\n4. Load "
		       "file\n5. Exit\nEnter choice: ");
		int c = 0;
		scanf("%d", &c);

		switch (c)
		{
		case 1: {
			int nr = 0;
			printf("Enter the number of records: ");
			scanf("%d", &nr);

			for (int i = 0; i < nr; i++)
			{
				getinput(&veh, n);
				n++;
			}
			break;
		}

		case 2: {
			Service *s = mostexp(veh, n);
			if (s)
			{
				printf("Most expensive service:\n");
				printService(s);
			}
			else
				printf("No records available.\n");
			break;
		}

		case 3: {
			int km;
			printf("Enter km limit: ");
			scanf("%d", &km);

			int saved = savekm(veh, n, km, "samfile.dat");
			if (saved >= 0)
				printf("Saved %d records to samfile.dat\n", saved);
			break;
		}

		case 4: {
			Service *loaded = NULL;
			int count = lloadf(&loaded, "samfile.dat");
			if (count > 0)
			{
				printf("Loaded %d records from file:\n", count);
				for (int i = 0; i < count; i++)
					printService(&loaded[i]);
			}
			free(loaded);
			break;
		}

		case 5:
			flag = 0;
			break;

		default:
			printf("Invalid choice.\n");
		}
	}

	free(veh);
	return 0;
}
