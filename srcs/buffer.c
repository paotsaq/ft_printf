/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 04:10:46 by apinto            #+#    #+#             */
/*   Updated: 2021/03/24 11:46:34 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// this whole function must have most of its conditions as variables in the struct

char	*creates_buffer(t_info *info)
{
	int		count;
	char	*res;
	char	*begg;
	int	min_number;
	int	width_chars;

	if (info->width > info->prec)
		width_chars = info->width - (info->prec + info->negative);
	count = ft_max(3, info->width, info->len, info->prec);
	res = calloc(count + 1, sizeof(char));
	if (!res)
		return (0);
	begg = res;
	while (!info->minus && info->prec && !(info->type == 's' && info->zero)  && width_chars--)
		*(res++) = ' ';
	if (info->negative)
		memset(res++, '-', 1);
	if (info->zero || (info->prec > info->len))
	{
		if (info->prec && !(info->type == 's' && info->zero))
			min_number = ft_min(2, info->prec - info->len, info->width - info->len);
		else
			min_number = info->width - info->len;
		memset(res, '0', min_number);
		res = res + min_number;
	}
	strlcat(res, info->content, info->len + 1);
	res = res + info->len;
	// generate whitespace function?
	if (info->minus)
		while ((res - begg) != count)
			*(res++) = ' ';
	return (begg);
}
