#include <stdio.h>

/* %d flag */
int		main()
{
	int x = 123456783;
	int y = 12;
	int z = 12345;
	printf("✨ FLAGS BEHAVIOUR ⏬\n\n");
   	printf("W | width is 6 -- offsets 4 units to the right, whitespace on the left ⏬\n");
	printf("this is a test with %6d", y);
	printf("\n-------\n");
	printf("W0 | the same, but whitespace is now 0 ⏬\n");
	printf("this is a test with %06d", y);
	printf("\n-------\n");
	printf("W0. | width is 6, precision is 3 ⏬ \n");
	printf("%06.3d", y);
	printf("\n-------\n");
	printf("* | first argument is W, next is d content ⏬\n");
	printf("%*d", 4, 4);
	printf("\n-------\n");
	printf("0* | same, but with 0 ⏬\n");
	printf("%0*d", 4, 4);
	printf("\n-------\n");
	printf("-W | aligns to the left, printing whitespace  ⏬\n");
	printf("%-10d", z);
	printf("\n-------\n");
	printf("0* | same, but with 0 (which gets ignored) ⏬\n");
	printf("%10d", z);
	printf("\n-------\n");
	printf(".* | precision is higher than number width ⏬\n");
	printf("%.5d", y);
	printf("\n-------\n");
	printf("-.* | precision is higher than number width - doesn't align left ⏬\n");
	printf("%-.5d", y);
	printf("\n-j-----\n");
	printf("*.| . overrides * when placed after! ⏬\n");
	printf("%*.4d", 5, y);
	printf("\n-------\n");
	printf("*.* | double asterisk, man! ⏬\n");
	printf("%*.*d", 5, 2, y);
	printf("\n-------\n");
	printf("-10.* | width + asterisk ⏬\n");
	printf("%-10.*d", 4, y);
	printf("\n-------\n");
	printf("10.-* | width + asterisk ⏬\n");
	printf("%10-.*d", 4, y);
	printf("\n-------\n");
}
