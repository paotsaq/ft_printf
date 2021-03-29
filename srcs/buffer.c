/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 04:10:46 by apinto            #+#    #+#             */
/*   Updated: 2021/03/29 06:56:01 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*creates_buffer(t_info *info)
{
	int		count;
	char	*res;
	char	*begg;

	count = info->width + info->len + info->prec;
	res = ft_calloc(count + 1, sizeof(char));
	if (!res)
		return (0);
	begg = res;
	while (!info->minus && info->width-- > 0)
		*(res++) = ' ';
	if (info->negative)
		ft_memset(res++, '-', 1);
	if (info->zero)
	{
		ft_memset(res, '0', info->zero);
		res += info->zero;
	}
	ft_strlcat(res, info->content, info->len + 1);
	res += info->len;
	while (info->minus--)
		*(res++) = ' ';
	return (begg);
}
