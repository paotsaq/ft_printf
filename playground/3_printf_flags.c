#include <stdio.h>

/* %d flag */
int		main()
{
	int x = 123456783;
	int y = 12;
	// if length of int is x = x' + n, width will offset by n units

	// offsets 4 units to the right (provides a block of 6 units)
	printf("W | width is 6 -- offsets 4 units to the right ⏬\n");
	printf("%6d", y);
	printf("\n-------\n");
	printf("W0 | the same, but whitespace is now 0 ⏬\n");
	printf("%06d", y);
	printf("\n-------\n");
	printf("W0. | ⚠️ \n");
	printf("%06.1d", y);
	printf("\n-------\n");
	printf("- | uses flag to keep left ⏬\n");
	printf("%-6d", y);
	printf("\n-------\n");
	printf("* | first argument is W, next is d content ⏬\n");
	printf("%*d", 4, 4);
	printf("\n-------\n");
	printf("0* | same, but with 0 ⏬\n");
	printf("%0*d", 2, 4);
	printf("\n-------\n");
	printf("-* | ⚠️  adjusts to the left ⏬\n");
	printf("%-*d", 4, 4);
	printf("\n-------\n");
	printf("*2$ | ⚠️  using 2nd argument (1, 4, 2) ⏬\n");
	printf("1st: %*2$d\n2nd: %d\n3rd: %d", 1, 4, 2);
	printf("\n-------\n");
}
