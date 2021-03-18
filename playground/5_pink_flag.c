#include <stdio.h>

int		main()
{
	int x = 123456783;
	int y = 123;
	unsigned int z = 1234;
	const char *s = "pinkflag1977 🌸\n";
	printf(".3s | precision on strings ✅\n");
	printf("%.3s", s);
	printf("\n-------\n");
	printf("0.3s | zero on strings 🔴\n");
	printf("%0.3s", s);
	printf("\n-------\n");
	printf("► precision on pointers ◄ 🔴\n");
	printf("%.3p", &s);
	printf("\n-------\n");
	printf("► width on pointers ◄ ✅\n");
	printf("%4p", &s);
	printf("\n-------\n");
	printf("► zero on pointers ◄ 🔴\n");
	printf("%012p", &s);
	printf("\n-------\n");
	printf("► width on unsigned ints ✅\n");
	printf("%7u", z);
	printf("\n-------\n");
	printf("► precision on ints ◄ 🔴\n");
	printf("%2.2i", 123456789);
	printf("\n-------\n");
}
