#include "ft_printf.h"
#include <limits.h>

int		main()
{
	printf("%3.2d\n", 2);
	ft_printf("%3.2d\n", 2);
	printf("%%04.3i 42 == |%04.3i|\n", 42);
	ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
}
