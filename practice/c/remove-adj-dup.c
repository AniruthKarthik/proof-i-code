#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	printf("enter a string: ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';
	printf("the og string: %s\n", str);
	char *ptr = str;
	char *tmp = str;
	tmp++;
	while (*tmp != '\0')
	{
		if (*tmp != *ptr)
		{
			ptr++;
			*ptr = *tmp;
		}
		tmp++;
	}
	*(++ptr) = '\0';

	printf("the answer string: %s\n", str);
}
