/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 04:10:46 by apinto            #+#    #+#             */
/*   Updated: 2021/03/22 11:31:52 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*creates_buffer(t_info *info)
{
	int		count;
	char	*res;
	char	*begg;
	int	min_number;
	int	width_chars;

	count = max(3, 0, info->width, info->len, info->prec);
	res = calloc(count + 1, sizeof(char));
	if (!res)
		return (0);
	begg = res;
	while (*(info->width)--)
		*(res++) = ' ';
	if (info->negative)
		memset(res++, '-', 1);
	if (info->zero || (info->prec > info->len))
	{
		// corrigir 
		min_number = min(2, 100000, info->prec - info->len, info->width - info->len);
		memset(res, '0', min_number);
		res = res + (count - min_number);
		count -= min_number;
	}
	strlcat(begg, info->content, max(3, 0, info->width, info->len, info->prec) + 1);
	res += info->len;
	count -= info->len;
	if (info->minus)
		while (count--)
			*(res++) = ' ';
	return (begg);
}
