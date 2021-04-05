/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_base_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:27:09 by apinto            #+#    #+#             */
/*   Updated: 2021/04/05 15:41:39 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	negative_cases(t_info *info, unsigned long long *content)
{
	if (!ft_strchr("uxX", info->type))
	{
		info->negative = 1;
		*content *= -1;
	}
	else
		*content += UINT_MAX + 1;
}

void	number_to_string(t_info *info, unsigned long long content,
			char *base, char *buffer)
{
	long long	len_of_base;
	char		digit;
	char		*begg;

	begg = buffer;
	len_of_base = (long long) ft_strlen(base);
	if (content == 0)
		*buffer = '0';
	if (content < 0)
		negative_cases(info, &content);
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
