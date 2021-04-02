#include <stdio.h>

int		main()
{
	int x = 1234;
	const char *s = "sexy printf";
	printf("width > prec > length, no 0\n");
	printf("%6.5d\n", x);
	printf("width > prec > length, 0\n");
	printf("%06.5d\n", x);
	printf("width > length, 0\n");
	printf("%06d\n", x);
	printf("width > length, no 0\n");
	printf("%6d\n", x);
	printf("-width > prec > length, no 0\n");
	printf("%-6.5d\n", x);
	printf("-width > prec > length, 0\n");
	printf("%-06.5d\n", x);
	printf("-width > length, 0\n");
	printf("%-06d\n", x);
	printf("-width > length, no 0\n");
	printf("%-6d\n", x);
	printf("zero precision, width < len (decimal)\n");
	printf("%*.0d\n", 3, 123456);
}
