#include <stdio.h>
#include "main.h"
int main(void)
{
	int len, len2;

	len = _printf("%p");
	len2 = printf("%");
	fflush(stdout);
	if (len != len2)
	{
		printf("_printf: %d,\nprintf %d\n",len,len2);
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
