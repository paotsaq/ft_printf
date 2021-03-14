#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{	
	char 	*str;
	int 	i;

	if (argc)
		str = argv[1];
	else
	{
		printf("please input something, senpai 🎎\n");			return (0);
	}
	i = -1;
	while (str[++i])
	//locate %
		if (strchr(&(str[i]), '%'))
		


}
