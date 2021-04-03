/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 04:10:46 by apinto            #+#    #+#             */
/*   Updated: 2021/04/03 19:44:00 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

static void	handles_content(t_info *info, char **begg, char **res, int size)
{
	char *empty;

	empty = "";
	if (info->type == 'c' && !info->chr)
	{
		writes_chars(*begg, *res);
		empty = ft_strdup("");
		writes_chars(empty, empty + 1);
		ft_bzero(*begg, size);
		*res = *begg;
		info->len = 0;
		free(empty);
	}
	else if (info->type == 'c' || info->type == '%')
		ft_memset(*res, info->chr, 1);
	else if (!info->content && info->type == 's')
		ft_strlcat(*res, "(null)", info->len + 1);
	else
		ft_strlcat(*res, (char *)info->content, 30);
}

void		writes_buffer(t_info *info)
{
	char	*begg;
	char	*res;
	int		size;

	size = info->width + info->negative + info->zero + info->len + info->minus + 1;
	res = ft_calloc(30, sizeof(char));
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
	handles_content(info, &begg, &res, size);
	res += info->len;
	while (info->minus--)
		*(res++) = ' ';
	write(1, begg, size);
	free(begg);
	begg = NULL;
}
