#include <stdarg.h>
#include <stdio.h>

void	testing_args(char *str, ...)
{
	va_list pargs;
	char	*arg;
	int i;

	va_start(pargs, str);
	while (*arg)
	{
		*arg = va_arg(pargs, char);
		printf("arg is %s\n", arg);
	}
	va_end(pargs);
}

int		main()
{
	char a;
	char b;

	a = 'a';
	b = 'b';
	testing_args("this is quite useless!\n", a, b);
	return (0);
}
