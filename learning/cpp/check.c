#include <stdio.h>

int main()
{
	char get[10];
	char scan[10];
	char c;
	fgets(get, sizeof(get), stdin);
	scanf("%s", scan);
	c = getchar();
	printf("getchar: %c", c);
	printf("fgets: %s", get);
	printf("scanf: %s\n", scan);

	return 0;
}
