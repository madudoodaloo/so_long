
#include "so_long.h"

void printhere(char **str)
{
	int i = -1;
	while (str[++i])
		printf("%s$\n", str[i]);
	return ;
}
