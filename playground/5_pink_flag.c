#include <stdio.h>

int		main()
{
	int x = 123456783;
	int y = 123;
	const char *s = "pinkflag1977 🌸\n";
	printf(".3s | precision on strings ✨\n");
	printf("%.3s", s);
	printf("\n-------\n");
	printf("0.3s | precision on strings 🔴\n");
	printf("%0.3s", s);
	printf("\n-------\n");
	printf("► precision on pointers ◄\n");
	printf("%.3p", &s);
	printf("\n-------\n");
}
