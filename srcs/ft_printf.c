/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 04:40:07 by apinto            #+#    #+#             */
/*   Updated: 2021/04/05 07:26:24 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			writes_chars(char *begg, char *str)
{
	int			length;
	static	int	total_length;

	length = str - begg;
	if (length)
		write(1, begg, length);
	total_length += length;
	return (total_length);
}

static void	reads_string(va_list *pargs, char *str)
{
	char	*begg;
	int		has_passed;

	begg = str;
	has_passed = 0;
	while (*str)
		if (*str == '%')
		{
			writes_chars(begg, str++);
			handles_conversion(pargs, &str);
			str++;
			has_passed = 0;
			if (*str)
				begg = str;
		}
		else
		{
			str++;
			has_passed = 1;
		}
	if (has_passed)
		writes_chars(begg, str);
}

int			ft_printf(const char *str, ...)
{
	va_list 	pargs;

	va_start(pargs, str);
	reads_string(&pargs, (char *)str);
	va_end(pargs);
	return (writes_chars((char *)str, (char *)str));
}
