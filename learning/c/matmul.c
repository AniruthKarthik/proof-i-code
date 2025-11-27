#include <stdio.h>

int main()
{
	int a[3][2] = {{2, 3}, {12, 2}, {23, 1}};
	int b[2][3] = {{2, 2, 3}, {2, 3, 5}};
	int c[3][3] = {0};

	for (int i = 0; i < 3; i++) // r1
	{
		for (int j = 0; j < 3; j++) // c2
		{
			for (int k = 0; k < 2; k++) // c1
			{

				c[i][i] += a[i][k] * b[k][j];
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}
}
