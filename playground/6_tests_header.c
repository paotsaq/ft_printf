#include "ft_printf.h"

int		main()
{
	int i = -1;
	t_flags result;
	
	while (++i < 7)
		printf("types[%d] = %c\nconv = [%d]\n", i, types[i], legal_conv[i][0]);
	return 0;
}
