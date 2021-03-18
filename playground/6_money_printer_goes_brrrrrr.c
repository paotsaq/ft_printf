#include <stdio.h>

int		main()
{
	int x = 123456783;
	unsigned int z = 9;
	const char *s = "pinkflag1977 🌸\n";
	printf(".3s | precision on strings ✅\n");
	printf("%.3s", s);
	printf("\n-------\n");
	printf("o | precision lower than converted number of digits✅\n");
	printf("%0.1o", z);
	printf("\n-------\n");
	printf("*.*s | double asterisk precision on strings ✅\n");
	printf("%*.*s", 4, 3, s);
	printf("\n-------\n");
	printf("-.*s | - and . options on strings ✅\n");
	printf("%-.*s", 30, s);
	printf("\n-------\n");
	printf(".*s | without - ✅\n");
	printf("%.*s", 30, s);
	printf("\n-------\n");
}
