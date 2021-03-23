# include "ft_printf.h"

int		main()
{
	printf("%0*.*d\n", 9, 5, -1234);
	ft_printf("%0*.*d\n", 9, 5, -1234);
	printf("%0*d\n", 9, 1234);
	ft_printf("%0*d\n", 9, 1234);
	printf("%0*.*s\n", 9, 5, "abcdef");
	ft_printf("%0*.*s\n", 9, 5, "abcdef");
	return (0);
}
