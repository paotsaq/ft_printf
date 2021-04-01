/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:30:43 by apinto            #+#    #+#             */
/*   Updated: 2021/04/01 06:27:19 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	handles_negative_width_prec(t_info *tr)
{
	if (tr->width < 0)
	{
		tr->minus = 1;
		tr->width *= -1;
	}
	if (tr->prec < 0)
	{
		tr->p_inp = 0;
		tr->prec = 0;
	}
}

static	void	general_attributions(t_info *tr)
{
	if (tr->p_inp && tr->type == 's' && tr->prec < tr->len)
		tr->len = tr->prec;
	else if (tr->prec > tr->len > 0 && tr->type != 's')
		tr->zero = tr->prec - tr->len;
	tr->prec = 0;
	if (tr->len > tr->width || (tr->len + tr->zero >= tr->width && tr->zero > 1))
		tr->width = 0;
	else if (tr->zero > 1)
		tr->width = tr->width - tr->len - tr->zero;
	else
		tr->width = tr->width - tr->len;
	if (tr->zero == 1 && !tr->minus)
	{
		tr->zero = tr->width;
		tr->width = 0;
	}
	if (tr->minus)
	{
		tr->minus = tr->width;
		tr->width = 0;
		if (tr->zero == 1)
			tr->zero = 0;
	}
}

void			cleans_info_with_prios(t_info *tr)
{
	if (!ft_strchr(TYPES, tr->type))
		tr->invalid = 1;
	handles_negative_width_prec(tr);
	general_attributions(tr);
}
