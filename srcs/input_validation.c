/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:30:43 by apinto            #+#    #+#             */
/*   Updated: 2021/04/02 06:04:27 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	handles_negative_width_prec(t_info *info)
{
	if (info->width < 0)
	{
		info->minus = 1;
		info->width *= -1;
	}
	if (info->prec < 0)
	{
		info->p_inp = 0;
		info->prec = 0;
	}
}

static	void	general_attributions(t_info *info)
{
	if (info->p_inp && info->type == 's' && info->prec < info->len)
		info->len = info->prec;
	else if (info->prec > info->len > 0 && info->type != 's')
		info->zero = info->prec - info->len;
	info->prec = 0;
	if (info->len > info->width || (info->len + info->zero >= info->width && info->zero > 1))
		info->width = 0;
	else if (info->zero > 1)
		info->width = info->width - info->len - info->zero;
	else
		info->width = info->width - info->len;
	if (info->negative)
		info->width -= 1;
	// missing negative conditions
	if (info->zero == 1 && !info->minus)
	{
		info->zero = info->width;
		info->width = 0;
	}
	if (info->minus)
	{
		info->minus = info->width;
		info->width = 0;
		if (info->zero == 1)
			info->zero = 0;
	}
}

void			cleans_info_with_prios(t_info *info)
{
	if (!ft_strchr(TYPES, info->type))
		info->invalid = 1;
	handles_negative_width_prec(info);
	general_attributions(info);
}
