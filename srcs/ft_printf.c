/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 04:40:07 by apinto            #+#    #+#             */
/*   Updated: 2021/04/07 04:11:17 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	writes_chars(char *begg, char *str, int last)
{
	int			length;
	static int	total_length;
	int			backup;

	length = str - begg;
	if (length)
		write(1, begg, length);
	total_length += length;
	if (last)
	{
		backup = total_length;
		total_length = 0;
		return backup;
	}
	return (total_length);
}

static void	reads_string(va_list *pargs, char *str)
{
	char	*begg;
	int		has_passed;

	begg = str;
	has_passed = 0;
	while (*str)
	{
		if (*str == '%')
		{
			writes_chars(begg, str++, 0);
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
	}
	if (has_passed)
		writes_chars(begg, str, 0);
}

int	ft_printf(const char *str, ...)
{
	va_list	pargs;

	va_start(pargs, str);
	reads_string(&pargs, (char *)str);
	va_end(pargs);
	return (writes_chars((char *)str, (char *)str, 1));
}
