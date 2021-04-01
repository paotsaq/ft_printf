/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 04:40:07 by apinto            #+#    #+#             */
/*   Updated: 2021/04/01 10:09:19 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reads_string(va_list *pargs, t_bfstr *buffer, int *total_length)
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
			if (parses_conversion(pargs, buffer, &i) == -1)
}


int		ft_printf(char *str, ...)
{
	va_list 	pargs;
	int			total_length;

	va_start(pargs, str);
	if (reads_string(&pargs, &tr, str) == -1)
		return (0);
	va_end(pargs);
	return (0);
}
