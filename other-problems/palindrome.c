// palindrome check

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool ispalindrome(char arr[], int st, int end)
{
	if (st >= end)
	{
		return true;
	}
	if (arr[st] != arr[end])
	{
		return false;
	}
	return ispalindrome(arr, st + 1, end - 1);
}

int main()
{

	/***
	printf("enter a word\n");
	char str[100] = "";
	scanf("%s", str);
	char *stptr = str;
	char *endptr = &str[strlen(str) - 1];
	while (stptr < endptr)
	{
	    if (tolower(*stptr) != tolower(*endptr))
	    {
	        printf("not a palindrome");
	        return 0;
	    }
	    stptr++;
	    endptr--;
	}
	printf("palindrome");
	return 0;
	***/

	printf("enter a word\n");
	char str[100] = "";
	scanf("%s", str);
	int end = strlen(str) - 1;
	bool pal = ispalindrome(str, 0, end);
	if (pal)
	{
		printf("palindrome");
	}
	else
	{
		printf("not a palindrome");
	}

	return 0;
}
