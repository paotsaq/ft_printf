#include <stdio.h>

int		main()
{
	int	d;

	d = 123;
	// printf("", d);

	// segmentation fault on no (obligatory) string
	// printf(d, d);
	// more variables than arguments
	// printf("%d", d, d);
	// segmentation fault on accessing string on int (becuase it dereferences)
	// printf("%s", d, d);
	// more conversions than data arguments
	printf("%d%d%d%d%d", d);
	return (0);
}
