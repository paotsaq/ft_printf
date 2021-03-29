/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:30:43 by apinto            #+#    #+#             */
/*   Updated: 2021/03/29 10:49:16 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 0bxy controls possible flags for each type.
 * x = zero flag (if 1, can apply)
 * y = precision (if 1, precision will trim)
 */
// static	int		flag_info(char c)
// {
// 	if (c == 'c' || c == 'p')
// 		return (0b00);
// 	else if (c == 's')
// 		return (0b01);
// 	else
// 		return (0b10);
// }

static	void	string_cleaning(t_info *tr)
{
	if (tr->p_inp && tr->prec == 0)
		tr->len = 0;
	// negative precision
	if (tr->prec < 0)
	{
		tr->p_inp = 0;
		tr->prec = tr->len;
	}
	if (tr->width < tr->len)
		tr->width = 0;
	if (tr->prec > tr->width && tr->prec > tr->len)
		tr->prec = tr->len;
	if (tr->p_inp && tr->prec < tr->len)
		tr->len = tr->prec;
}

static	void	general_cleaning(t_info *tr)
{
	if (tr->width < 0)
	{
		tr->minus = 1;
		tr->width *= -1;
	}
	if (tr->minus)
		tr->zero = 0;
}

static	void	general_attributions(t_info *tr)
{
	if (tr->zero || (tr->prec > tr->len && tr->type != 's'))
		tr->zero = ft_max(2, tr->prec, tr->width) - tr->len;
	if (!tr->minus && tr->width > tr->len)
	{
		tr->width -= (tr->prec * tr->p_inp + tr->negative + tr->len + tr->zero);
		if (tr->width < 0)
			tr->width = 0;
	}
	if (tr->minus)
		if (tr->width > tr->prec)
			tr->minus = tr->width - ft_max(2, tr->prec, tr->len);
}

void			cleans_info_with_prios(t_info *tr)
{
	if (!ft_strchr(TYPES, tr->type))
		tr->invalid = 1;
	general_cleaning(tr);
	if (tr->type == 's')
		string_cleaning(tr);
	else
	{
		if (tr->prec < 0)
			tr->prec = 0;
	}
	general_attributions(tr);
	tr->size = (tr->len + tr->width + tr->zero + tr->minus);
}
