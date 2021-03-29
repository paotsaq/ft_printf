/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 04:10:46 by apinto            #+#    #+#             */
/*   Updated: 2021/03/29 06:14:44 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*creates_buffer(t_info *info)
{
	int		count;
	char	*res;
	char	*begg;
	int		zero_chars;
	int		width_chars;

	count = ft_max(3, info->width, info->len, info->prec);
	res = ft_calloc(count + 1, sizeof(char));
	if (!res)
		return (0);
	begg = res;
	// at which types does this apply?
	// might turn into a struct property
	if (!info->zero && !info->minus && info->width > info->len)
	{
		width_chars = info->width - (info->prec * info->p_inp + info->negative);
		while (width_chars--)
			*(res++) = ' ';
	}
	if (info->negative)
		ft_memset(res++, '-', 1);
	if (info->zero || (info->prec > info->len && info->type != 's'))
	{
		zero_chars = ft_max(2, info->prec, info->width) - info->len;
		ft_memset(res, '0', zero_chars);
		res += zero_chars;
	}
	ft_strlcat(res, info->content, count - (res - begg) + 1);
	res = res + info->len;
	// generate whitespace function?
	if (info->minus)
		while ((res - begg) != count)
			*(res++) = ' ';
	return (begg);
}
