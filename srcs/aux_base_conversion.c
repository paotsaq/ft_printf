/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_base_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:27:09 by apinto            #+#    #+#             */
/*   Updated: 2021/04/05 10:48:17 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	number_to_string(t_info *info, unsigned long long content, char *base, char *buffer)
{
	long long	len_of_base;
	char		digit;
	char		*begg;

	begg = buffer;
	len_of_base = (long long) ft_strlen(base);
	if (content == 0)
		*buffer = '0';
	if (content < 0)
	{
		if (!ft_strchr("uxX", info->type))
		{
			info->negative = 1;
			content *= -1;
		}
		else
			content = UINT_MAX + content + 1;

	}
	while (content != 0)
	{
		digit = base[content % len_of_base];
		*(buffer++) = digit;
		content = content / len_of_base;
	}
	if (info->type == 'p')
		ft_strlcat(buffer, "x0", BUFF_LEN);
	ft_strrev(begg);
	info->content = begg;
	info->len = ft_strlen(begg);
}
