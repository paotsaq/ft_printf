#include <stdio.h>

int		main()
{
	int	d;

	d = 123;
	printf("empty string w/ arguments ⏬\n");
	printf("", d, d, d, d);
	printf("\n-------\n");

	printf("invalid flag passed on %⏬\n");
	printf("%q %z", d, d);
	printf("\n-------\n");
	// segmentation fault on no (obligatory) string
	// printf(d, d);
	// more variables than arguments
	// printf("%d", d, d);
	printf("segmentation fault on accessing string on int (because it dereferences) ⏬\n");
	printf("printf(\"%%s\", d, d);\n");
	printf("-------\n");
	printf("more conversions than data arguments ⏬ (unpredictable)\n");
	printf("%d\n%d\n%d\n%d\n%d", d);
	printf("-------\n");
	printf("%%%d\n%d\n%d\n%d\n%d", d);
	return (0);
}
