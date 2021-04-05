#include "ft_printf.h"

int		main()
{
	printf(" %p %p \n", LONG_MIN, LONG_MAX);
	ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
	printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
}
