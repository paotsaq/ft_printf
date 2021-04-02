/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 04:40:07 by apinto            #+#    #+#             */
/*   Updated: 2021/04/02 05:54:48 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reads_string(va_list *pargs, char *str, int *total_length)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			if (i != 0)
				write(1, str, i);
			write(1, "%", 1);
			*total_length +=  i + 1;
			i += 2;
			str = &str[i];
			i = -1;
		}
		else if (str[i] == '%')
		{
			if (i != 0)
				write(1, str, i);
			handles_conversion(pargs, str, &i);
			*total_length += i;
			str = &str[i + 1];
			i = -1;
		}
	}
}

int		ft_printf(char *str, ...)
{
	va_list 	pargs;
	int			total_length;

	total_length = 0;
	va_start(pargs, str);
	reads_string(&pargs, str, &total_length);
	va_end(pargs);
	printf("\n%d\n", total_length);
	return (total_length);
}
