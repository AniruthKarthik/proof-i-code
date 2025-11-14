#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // max chars per line

// Global variables
char **lines = NULL; // pointer to pointer for lines
int total_lines = 0;

// Function prototypes
void addLine();
void displayLines();
void editLine();
void deleteLine();

int main()
{
	int choice;

	while (1)
	{
		printf("\n=== Mini Text Editor ===\n");
		printf("1. Add new line\n");
		printf("2. Display all lines\n");
		printf("3. Edit a line\n");
		printf("4. Delete a line\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		getchar(); // consume newline left by scanf

		switch (choice)
		{
		case 1:
			addLine();
			break;
		case 2:
			displayLines();
			break;
		case 3:
			editLine();
			break;
		case 4:
			deleteLine();
			break;
		case 5:
			// free memory before exiting
			for (int i = 0; i < total_lines; i++)
				free(lines[i]);
			free(lines);
			printf("Exiting...\n");
			exit(0);
		default:
			printf("Invalid choice! Try again.\n");
		}
	}
	return 0;
}
char *getinput()
{
	char *str = malloc(MAX_LINE_LENGTH);

	printf("Enter text (press Enter to stop):\n");

	fgets(str, MAX_LINE_LENGTH, stdin);
	str[strcspn(str, "\n")] = '\0';

	return str;
}

// Function definitions (empty for now)
void addLine()
{
	if (total_lines == 0)
	{
		lines = malloc(sizeof(char *) * 1);
	}
	else
	{
		lines = realloc(lines, (total_lines + 1) * sizeof(char *));
	}
	lines[total_lines] = getinput();
	total_lines++;
}

void displayLines()
{
	if (total_lines == 0)
	{
		printf("no lines to display\n");
	}
	for (int i = 0; i < total_lines; i++)
	{
		printf("%s\n", lines[i]);
	}
}

void editLine()
{
	if (total_lines == 0)
	{
		printf("no lines to edit\n");
		return;
	}
	int n;
	while (1)
	{
		printf("Enter line number to edit (1-%d): ", total_lines);
		scanf("%d", &n);
		getchar();
		if (n < 1 || n > total_lines)
		{
			printf("Invalid input\n");
			continue;
		}
		free(lines[n - 1]);
		lines[n - 1] = getinput();
		break;
	}
}
void deleteLine()
{
	if (total_lines == 0)
	{
		printf("no lines to delete\n");
		return;
	}
	int n;
	while (1)
	{
		printf("Enter line number to edit (1-%d): ", total_lines);
		scanf("%d", &n);
		getchar();
		if (n < 1 || n > total_lines)
		{
			printf("Invalid input\n");
			continue;
		}
		free(lines[n - 1]);
		for (int i = n - 1; i < total_lines - 1; i++)
		{
			lines[i] = lines[i + 1];
		}
		total_lines--;
		break;
	}
}
