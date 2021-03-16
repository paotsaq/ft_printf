#include <stdio.h>

int		main()
{
	int x = 123456783;
	int y = 123;
	printf("breaks after d mention ⏬\n");
	printf("%02.3d*.4d", x);
	printf("\n-------\n");
	printf("-.* | precision is lower than number width - doesn't change ⏬\n");
	printf("%*.4d", 200, x);
	printf("\n-------\n");
	printf("----W | many - are allowed! ⏬\n");
	printf("%------20d", x);
	printf("\n-------\n");
	printf("000 | many 0 are allowed! ⏬\n");
	printf("%000d", y);
	printf("\n-------\n");
	printf("0W.* | . trumps width if larger (w/ smaller number) ⏬\n");
	printf("%004.*d", 5, y);
	printf("\n-------\n");
	printf("W.* | precision larger than width without 0 flag ⏬\n");
	printf("%4.*d", 5, y);
	printf("\n-------\n");
	printf("W | no precision  ⏬\n");
	printf("%4d", y);
	printf("\n-------\n");
	printf("0W.* | width trumps . if larger (w/ smaller number) ⏬\n");
	printf("%006.*d", 5, y);
	printf("\n-------\n");
	printf("0W.* | . trumps width if larger (w/ larger number) ⏬\n");
	printf("%004.*d", 5, x);
	printf("\n-------\n");
	printf("0W.* | width trumps . if larger (w/ larger number) ⏬\n");
	printf("%006.*d", 5, x);
	printf("\n-------\n");
}
