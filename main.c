#include "ft_printf.h"
#include <limits.h>

int		main()
{
	printf(" %-.2d \n", 0);
	printf(" %-.2d \n", 0);
	ft_printf(" %-.2d \n", 0);
	printf(" %-2.2d \n", 0);
	ft_printf(" %-2.2d \n", 0);
	printf(" %-3.2d \n", 0);
	ft_printf(" %-3.2d \n", 0);
	printf(" %-3.2d %10.42d \n", 0, 0);
	ft_printf(" %-3.2d %10.42d \n", 0, 0);
	printf(" %-3.2d %10.42d \n", 1, -1);
	ft_printf(" %-3.2d %10.42d \n", 1, -1);
	// printf("===\n");
	// printf("%%04.3i 42 == |%04.3i|\n", 42);
	// ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
	// printf("===\n");
	// printf("%%04.2i 42 == |%04.2i|\n", 42);
	// ft_printf("%%04.2i 42 == |%04.2i|\n", 42);
}
