# include <stdio.h>
# include <string.h>
# include "ft_printf.h"
# include <assert.h>

int		main()
{
	// printf("0, w > len > p\n");
	// printf("%-0*.*s\n", 9, 5, "abcdef");
	// ft_printf("%-0*.*s\n", 9, 5, "abcdef");
	// printf("negative width\n");
	// printf("%-5c\n", 'e');
	// ft_printf("%-5c\n", 'e');
	// printf("%-5.2s\n", "ola");
	// ft_printf("%-5.2s\n", "ola");
	// printf("%-0*.*s\n", -9, 5, "abcdef");
	// ft_printf("%-0*.*s\n", -9, 5, "abcdef");
	// printf("negative precision, positive width\n");
	// printf("%-0*.*s\n", 9, -5, "abcdef");
	// ft_printf("%-0*.*s\n", 9, -5, "abcdef");
	// printf("precision > width\n");
	// printf("%-0*.20s\n", 9, "abcdef");
	// ft_printf("%-0*.20s\n", 9, "abcdef");
	// //printf("%-0*.20s\n", 4, "abcdef");
	// //ft_printf("%-0*.20s\n", 4, "abcdef");
	// printf("width > precision\n");
	// printf("%-0*.3s\n", 4, "abcdef");
	// ft_printf("%-0*.3s\n", 4, "abcdef");
	// printf("0 and precision less than width\n");
	// printf("%0*.3s\n", 5, "abcdef");
	// ft_printf("%0*.3s\n", 5, "abcdef");
	// // width < precision < len
	// //printf("%-0*.5s\n", 3, "abcdef");
	// //ft_printf("%-0*.5s\n", 3, "abcdef");
	printf("0, precision > width \n");
	printf("%-0*.20d\n", 9, 123456);
	ft_printf("%-0*.20d\n", 9, 123456);
	// printf("- and width > len\n");
	// printf("%-10d\n", 123456);
	// ft_printf("%-10d\n", 123456);
	// printf("-0 and width > len\n");
	// printf("%-010d\n", 123456);
	// ft_printf("%-010d\n", 123456);
	// printf("-0 and prec > width > len\n");
	// printf("%-010.12d\n", 123456);
	// ft_printf("%-010.12d\n", 123456);
	// printf("-0 and prec > width, but len > prec\n");
	// printf("%-03.4d\n", 123456);
	// ft_printf("%-03.4d\n", 123456);
	// //printf("%10.20d\n", 123456);
	// //ft_printf("%10.20d\n", 123456);
	// printf("width < len\n");
	// printf("%*s\n", 3, "abcdef");
	// ft_printf("%*s\n", 3, "abcdef");
	// printf("zero precision, width < len\n");
	// printf("%*.0s\n", 3, "abcdef");
	// ft_printf("%*.0s\n", 3, "abcdef");
	// printf("zero precision, width > len\n");
	// printf("%*.0s\n", 10, "abcdef");
	// ft_printf("%*.0s\n", 10, "abcdef");
	// printf("negative precision with bigger width on string\n");
	// printf("%*.*s\n", 10, -4, "abcdef");
	// ft_printf("%*.*s\n", 10, -4, "abcdef");
	// printf("negative precision on string\n");
	// printf("%.*s\n", -4, "abcdef");
	// ft_printf("%.*s\n", -4, "abcdef");
	return (0);
}
