#include "ft_printf.h"
#include <math.h>

int		main()
{
	int exp;
	printf("%d\n", C_FLAGS);

	/* we can discard pow function! */
	exp = -1;
	while (++exp != 8)
		printf("exp: %d; equality to 1: %d\n", exp, (C_FLAGS>>exp & 1));

	return C_FLAGS;
}
