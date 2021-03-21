/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 04:40:07 by apinto            #+#    #+#             */
/*   Updated: 2021/03/21 21:52:04 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prints_params(t_info *tr)
{
	printf("0: %d\n", tr->zero);
	printf("-: %d\n", tr->minus);
	printf("w: %d\n", tr->width);
	printf("p: %d\n", tr->prec);
	printf("p*: %d\n", tr->p_aster);
	printf("w*: %d\n", tr->w_aster);
	printf("type: %c\n", tr->type);
	printf("len: %d\n", tr->len);
	printf("invalid: %d\n", tr->invalid);
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
	printf("prints before cleaning 🧹\n");
	prints_params(&tr);
	cleans_info_with_prios(&tr);
	printf("prints after cleaning 🧹\n");
	prints_params(&tr);

	return (0);
}
