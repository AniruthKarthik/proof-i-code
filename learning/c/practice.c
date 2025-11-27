#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	printf("enter a string:\n>> ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';
	printf("%s is the string that you have entered entered\n", str);
	printf("%zu is the length of the string", strlen(str));
	return 0;
}
