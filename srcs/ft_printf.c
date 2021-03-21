/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 04:40:07 by apinto            #+#    #+#             */
/*   Updated: 2021/03/21 16:02:47 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prints_params(t_info *tr)
{
	printf("%d\n", tr->zero);
	printf("%d\n", tr->minus);
	printf("%d\n", tr->width);
	printf("%d\n", tr->prec);
	printf("%d\n", tr->p_aster);
	printf("%d\n", tr->w_aster);
	printf("%c\n", tr->type);
	printf("%d\n", tr->len);
	printf("%d\n", tr->invalid);
}

int		ft_printf(char *str, ...)
{
	va_list 	pargs;
	int			arg;
	t_info		tr;

	initializes_tr(&tr);
	va_start(pargs, str);
	parses_string(&tr, str, &pargs);
	va_end(pargs);
	cleans_info_with_prios(&tr);
	prints_params(&tr);
	return (0);
}
