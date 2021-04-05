/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:30:43 by apinto            #+#    #+#             */
/*   Updated: 2021/04/05 10:10:38 by apinto           ###   ########.fr       */
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
	if (info->type == 's' && info->p_inp && info->prec < info->len)
		info->len = info->prec;
	else if (info->p_inp && info->prec <= info->len)
		info->zero = 0;
	else if (!ft_strchr("sc%", info->type) && info->prec > info->len)
		info->nbr_zeros = ft_max(2, info->prec - info->len, 0);
	if (info->len + info->nbr_zeros >= info->width)
		info->width = 0;
	else if (info->nbr_zeros > 0)
		info->width = info->width - info->len - info->nbr_zeros;
	else
		info->width = info->width - info->len;
	if (info->negative && info->width > 0)
		info->width -= 1;
	if (info->zero == 1 && !info->nbr_zeros && !info->minus)
	{
		info->nbr_zeros = info->width;
		info->width = 0;
	}
	if (info->minus)
	{
		info->minus = info->width;
		info->width = 0;
	}
}

void			cleans_info_with_prios(t_info *info)
{
	if (!info->invalid)
	{
		handles_negative_width_prec(info);
		general_attributions(info);
	}
}
