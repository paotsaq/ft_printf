# include "ft_printf.h"

int		main()
{
	ft_printf("%0*.*d\n", 9, 5, -1234);
	printf("%0*.*d\n", 9, 5, -1234);
	//ft_printf("%0*.*d\n", 9, 5, 1234);
	//printf("%0*.*d\n", 9, 5, 1234);
	//char *test = strdup("abcdef");
	//ft_printf("%0*.*s\n", 9, 5, test);
	//printf("%0*.*s\n", 9, 5, test);
	//free(test);
	return (0);
}
