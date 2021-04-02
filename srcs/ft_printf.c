/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 04:40:07 by apinto            #+#    #+#             */
/*   Updated: 2021/04/02 11:25:33 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		writes_passed_chars(char *begg, char *str)
{
	int			length;
	static	int	total_length;

	length = str - begg;
	if (length)
		write(1, begg, length);
	total_length += length;
	return (total_length);
}

void	reads_string(va_list *pargs, char *str)
{
	char *begg;

	begg = str;
	while (*str)
		if (*str == '%')
		{
			if (*(str + 1) == '%')
			{
				writes_passed_chars(begg, (str + 1));
				str += 2;
				begg = str;
				break;
			}
			else
			{
				writes_passed_chars(begg, str++);
				handles_conversion(pargs, &str);
				str++;
			}
			if (*str)
				begg = str++;
		}
		else
			str++;
	writes_passed_chars(begg, str);
}

int		ft_printf(char *str, ...)
{
	va_list 	pargs;

	va_start(pargs, str);
	reads_string(&pargs, str);
	va_end(pargs);
	return (writes_passed_chars(str, str));
}
