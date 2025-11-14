#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char buffer[1024];

	printf("Enter text (press Enter to stop):\n");

	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0';
	char *str = malloc(strlen(buffer) + 1);
	strcpy(str, buffer);

	printf("%s", buffer);

	return 0;
}
