#include <stdio.h>
#include <string.h>

int sumofarr(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
void alterarr(int arr[]) { arr[0] = 101; }
int main()
{
	int arr[10];
	char dummy[10];
	dummy[0] = 1;
	printf("%d\n", dummy[0]);
	printf("%d\n", dummy[1]);
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("sum: %d\n", sumofarr(arr, n));
	alterarr(arr);
	printf("sum: %d\n", sumofarr(arr, n));

	return 0;
}
