# include "ft_printf.h"

int		main()
{
	ft_printf(" %0*.*d\n", 9, 7, -1234);
	printf(" %0*.*d\n", 9, 7, -1234);
	return (0);
}
