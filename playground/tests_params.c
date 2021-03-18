#include "ft_printf.h"


int		main()
{
	int 	j;
	t_flags	tr;
	int		i;

	ft_printf("%0*d\n", 4, 42);

	while (++i < 7)
		printf("types[%d] = %c\nconv = [%d]\n", i, types[i], legal_conv[i][0]);

	return 0;
}
