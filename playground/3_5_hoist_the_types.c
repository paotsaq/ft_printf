#include <stdio.h>

int		main()
{
	char c = 'a';
	char *s = "some sexy code pls";
	int d = 123456789;

   	printf("CHAR TESTS 💫 \n");
   	printf("0c | simple zero test 🔴\n");
	printf("%0c", c);
	printf("\n-------\n");
   	printf("4c | simple width test ⏬\n");
	printf("%4c", c);
	printf("\n-------\n");
   	printf("-4c | simple (minus) width test ⏬\n");
	printf("%-4c", c);
	printf("\n-------\n");
   	printf("4.2c | simple precision test 🔴 \n");
	printf("%4.2c", c);
	printf("\n-------\n");

   	printf("STRING TESTS 💫 \n");
   	printf("4s | simple width test ⏬\n");
	printf("%20s", s);
	printf("\n-------\n");
   	printf("-4s | simple minus test ⏬\n");
	printf("%-30s", s);
	printf("\n-------\n");
   	printf("4.2s | simple width + precision test ⏬\n");
	printf("%4.2s", s);
	printf("\n-------\n");

   	printf("INT/DEC TESTS 💫 \n");
   	printf("2.4s | does it have precision? ⏬\n");
	printf("%2.4d", d);
	printf("\n-------\n");
   	printf("2.4s | what happens w/ 0-? 🔴\n");
	printf("%0-20d", d);
	printf("\n-------\n");

   	printf("ZERO TESTS 💫 \n");
   	printf("010d | how does zero behave with negative? ⏬\n");
	printf("%010d", -123);
	printf("\n-------\n");

   	printf("NEG WDT TESTS 💫 \n");
   	printf("*d | omg? ⏬\n");
	printf("%*d", -4, 123);
	printf("\n-------\n");
   	printf("-*d | omg? ⚠️\n");
	printf("%0*d", -4, 123);
	printf("\n-------\n");
}
