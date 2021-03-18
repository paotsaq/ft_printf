/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 04:40:07 by apinto            #+#    #+#             */
/*   Updated: 2021/03/18 05:00:31 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prints_params(t_flags *tr)
{
	printf("%d\n", tr->zero);
	printf("%d\n", tr->minus);
	printf("%d\n", tr->width);
	printf("%d\n", tr->prec);
	printf("%d\n", tr->p_aster);
	printf("%d\n", tr->w_aster);
}

int		ft_printf(char *str, ...)
{
	va_list 	pargs;
	int			arg;
	t_flags		tr;

	initializes_tr(&tr);

	va_start(pargs, str);
	parses_string(&tr, str, &pargs);

	prints_params(&tr);
	va_end(pargs);
	return (0);
}
