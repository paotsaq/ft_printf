/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 04:10:46 by apinto            #+#    #+#             */
/*   Updated: 2021/04/02 12:21:37 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	writes_buffer(t_info *info)
{
	char	*begg;
	char	*res;
	int		size;

	size = info->width + info->negative + info->zero + info->len + info->minus;
	res = ft_calloc(size, sizeof(char));
	if (!res)
		return;
	begg = res;
	while (!info->minus && info->width-- > 0)
		*(res++) = ' ';
	if (info->negative)
		ft_memset(res++, '-', 1);
	if (info->zero)
		ft_memset(res, '0', info->zero);
	res += info->zero;
	if (info->content)
		ft_strlcat(res, info->content, info->len + 1);
	res += info->len;
	while (info->minus--)
		*(res++) = ' ';
	write(1, begg, (int)ft_strlen(begg));
	free(begg);
}
