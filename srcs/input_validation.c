/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:30:43 by apinto            #+#    #+#             */
/*   Updated: 2021/03/30 16:21:26 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	string_cleaning(t_info *tr)
{
	if (tr->minus)
		tr->zero = 0;
	if (tr->p_inp && tr->prec == 0)
		tr->len = 0;
	// negative precision
	if (tr->prec < 0)
		tr->p_inp = 0;
	if (tr->p_inp && tr->prec < tr->len)
		tr->len = tr->prec;
	if (tr->width < tr->len)
		tr->width = 0;
	if (tr->p_inp && tr->prec > tr->width && tr->prec > tr->len)
		tr->prec = tr->len;
}

static	void	general_cleaning(t_info *tr)
{
	if (tr->width < 0)
	{
		tr->minus = 1;
		tr->width *= -1;
	}
}

static	void	general_attributions(t_info *tr)
{
	if (tr->zero && (tr->width > tr->len || tr->prec > tr->len))
		tr->zero = ft_max(2, tr->width, tr->p_inp * tr->prec) - tr->len;
	if (!tr->minus && tr->width > tr->len)
	{
		tr->width -= (tr->prec * tr->p_inp + tr->negative + tr->len + tr->zero);
		if (tr->width < 0)
			tr->width = 0;
	}
	if (tr->minus)
//	if (tr->p_inp && tr->width > tr->prec)
			tr->minus = ft_max(2, 0, tr->width - tr->len);
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
