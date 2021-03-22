/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 04:10:46 by apinto            #+#    #+#             */
/*   Updated: 2021/03/22 09:22:39 by apinto           ###   ########.fr       */
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
	width_chars = (info->width - info->prec);
	while (width_chars--)
		*(res++) = ' ';
	if (info->negative)
		memset(res++, '-', 1);
	if (info->zero || (info->prec > info->len))
	{
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

//int		main()
//{
//	t_info info;
//	char *str;
//
//	info.content = strdup("what boi🍔");
//	info.len = 10;
//	info.minus = 1;
//	info.width = 100;
//	str = creates_buffer(&info);
//	free(info.content);
//	printf("%s\n", str);
//	free(str);
//	return (0);
//}
