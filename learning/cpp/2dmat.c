#include <stdio.h>

int main()
{
	int arr[4][4];
	int diag = 0;
	int ndiag = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("enter the val at %d,%d: ", i + 1, j + 1);
			scanf("%d", &arr[i][j]);
			if (i == j)
			{
				diag += arr[i][j];
			}
			else
			{
				ndiag += arr[i][j];
			}
		}
	}
	printf("the sumof diagonals is :%d\n", diag);
	printf("the sumof non diagonals is :%d\n", ndiag);
}
