# include <stdio.h>
#include "ft_printf.h"

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
	printf("%-0*.*s\n", 9, -5, "abcdef");
	ft_printf("%-0*.*s\n", 9, -5, "abcdef");
	printf("%-0*.20s\n", 9, "abcdef");
	ft_printf("%-0*.20s\n", 9, "abcdef");
	printf("%-0*.20s\n", 4, "abcdef");
	ft_printf("%-0*.20s\n", 4, "abcdef");
	// precision < width < len
	printf("test\n");
	printf("%-0*.3s\n", 4, "abcdef");
	ft_printf("%-0*.3s\n", 4, "abcdef");
	// width < precision < len
	printf("%-0*.5s\n", 3, "abcdef");
	ft_printf("%-0*.5s\n", 3, "abcdef");
	printf("%-0*.20d\n", 9, 123456);
	ft_printf("%-0*.20d\n", 9, 123456);
	printf("width < len\n");
	printf("%*s\n", 3, "abcdef");
	ft_printf("%*s\n", 3, "abcdef");
	printf("zero precision\n");
	printf("%*.0s\n", 3, "abcdef");
	ft_printf("%*.0s\n", 3, "abcdef");
	return (0);
}
