#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ft_strtoupper(char *str);
char	ft_toupper(int c);


int		main()
{
	char *test= strdup("abcde");
	ft_strtoupper(test);
	printf("%s\n", test);
}
