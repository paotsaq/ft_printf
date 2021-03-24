# include "ft_printf.h"

int		main()
{
	printf("%0*.*d\n", 9, 5, -1234);
	ft_printf("%0*.*d\n", 9, 5, -1234);
	printf("%0*d\n", 9, 1234);
	ft_printf("%0*d\n", 9, 1234);
	printf("%0*.*s\n", 9, 5, "abcdef");
	ft_printf("%0*.*s\n", 9, 5, "abcdef");
	printf("%-0*.*s\n", 9, 5, "abcdef");
	ft_printf("%-0*.*s\n", 9, 5, "abcdef");
	printf("%-5c\n", 'e');
	ft_printf("%-5c\n", 'e');
	printf("%-5.2s\n", "ola");
	ft_printf("%-5.2s\n", "ola");
	printf("%-0*.*s\n", -9, 5, "abcdef");
	ft_printf("%-0*.*s\n", -9, 5, "abcdef");
	printf("%-0*.*s\n", -9, 5, "abcdef");
	ft_printf("%-0*.*s\n", -9, 5, "abcdef");
	printf("%-0*.*s\n", 9, -5, "abcdef");
	ft_printf("%-0*.*s\n", 9, -5, "abcdef");
	return (0);
}
