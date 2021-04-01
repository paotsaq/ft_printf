/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 04:40:07 by apinto            #+#    #+#             */
/*   Updated: 2021/04/01 17:12:19 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reads_string(va_list *pargs, int *total_length)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			write(1, "%", 1);
			total_length++;
			i += 2;
		}
		else if (str[i] == '%')
		{
			if (i != 0)
				write(1, str, i - 1);
			handles_conversion(pargs, str, &i);
			total_length += i;
		}
	}
}

int		ft_printf(char *str, ...)
{
	va_list 	pargs;
	int			total_length;

	va_start(pargs, str);
	reads_string(&pargs, &total_length)
	va_end(pargs);
	return (0);
}
