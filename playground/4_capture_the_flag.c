#include <stdio.h>

int		main()
{
	int x = 123456783;
	printf("breaks after d mention ⏬\n");
	printf("%02.3d*.4d", x);
	printf("\n-------\n");
	printf("-.* | precision is lower than number width - doesn't change ⏬\n");
	printf("%*.4d", 200, x);
	printf("\n-------\n");
}
