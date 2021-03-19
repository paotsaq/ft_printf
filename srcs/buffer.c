/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 04:10:46 by apinto            #+#    #+#             */
/*   Updated: 2021/03/19 11:52:36 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// zero and minus conflict must have been solved by now!
char	*creates_buffer(t_info *info)
{
	int		count;
	char	*res;
	char	*begg;

	count = max(3, info->width, info->len, info->prec);
	res = calloc(count + 1, sizeof(char));
	if (!res)
		return (0);
	begg = res;
	if (info->zero)
	{
		memset(res, '0', count - info->len);
		res = res + (count - info->len);
		count -= info->len;
	}
	strlcat(res, info->content, count + 1);
	res += info->len;
	count -= info->len;
	if (info->minus)
		while (count--)
			*(res++) = ' ';
	return (begg);
}

int		main()
{
	t_info info;
	char *str;

	info.content = strdup("what boi🍔");
	info.len = 10;
	info.minus = 1;
	info.width = 100;
	str = creates_buffer(&info);
	free(info.content);
	printf("%s\n", str);
	free(str);
	return (0);
}
