/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 04:45:06 by apinto            #+#    #+#             */
/*   Updated: 2021/03/16 11:29:12 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	va_list 	pargs;
	int			arg;
	int 		i;
	t_flags		tr;

	initializes_tr(&tr);

	i = -1;
	va_start(pargs, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			checks_flags(&tr, str, &i);
			checks_width(&tr, str, &i, &pargs);
			checks_prec(&tr, str, &i, &pargs);
			checks_type(&tr, str, &i, &pargs);
		}
	}
	va_end(pargs);
	return (0);
}

int		main(int argc, char **argv)
{
	int 	j;
	t_flags	tr;
	char 	*str;

	ft_printf("%0*d\n", 4, 42); 
	//if (argc == 2)
	//	str = argv[1];
	//else
	//{
	//	printf("Please print include some string! 🧵\n");
	//	return (0);
	//}
}
