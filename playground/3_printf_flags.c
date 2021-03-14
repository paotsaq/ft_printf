#include <stdio.h>

int		main()
{
	int x = 123456783;
	int y = 12;
	// if length of int is x, width will offset by n units if length = x' + n
	printf("%06.2d\n", y);
	printf("%0.6d\n", y);
	printf("%06d\n", y);
	printf("%0*9d\n", 1, 2);
}
