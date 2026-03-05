#include <cstring>
#include <stdio.h>

void reversestr(char arr[], int a, int b)
{
	if (a >= b)
	{
		return;
	}
	char c = arr[a];
	arr[a] = arr[b];
	arr[b] = c;
	reversestr(arr, a + 1, b - 1);
}

int main()
{
	char arr[] = "1234567";
	int a = 0;
	int b = strlen(arr) - 1;
	printf("%s\n", arr);
	reversestr(arr, a, b);
	printf("%s\n", arr);
	int c = 2;
	int d = 3;
	int e = ++c + d--;
	printf("%d\n", e);
}
