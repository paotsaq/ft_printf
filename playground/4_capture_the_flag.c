#include <stdio.h>

int		main()
{
	int x = 123456783;
	int y = 123;
	printf("breaks after d mention ⏬\n");
	printf("%02.3d*.4d", x);
	printf("\n-------\n");
	printf("-.* | precision is lower than number width - doesn't change ⏬\n");
	printf("%*.4d", 200, x);
	printf("\n-------\n");
	printf("----W | many - are allowed! ⏬\n");
	printf("%------20d", x);
	printf("\n-------\n");
	printf("000 | many 0 are allowed! ⏬\n");
	printf("%000d", y);
	printf("\n-------\n");
	printf("-.* | many 0 are allowed w/ * ⏬\n");
	printf("%0004*d", 7, y);
	printf("\n-------\n");
}
