/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_base_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:27:09 by apinto            #+#    #+#             */
/*   Updated: 2021/04/02 04:13:02 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	number_to_string(t_info *tr, long long content, char *base, char *buffer)
{
	long long	len_of_base;
	char		digit;
	char		*begg;

	begg = buffer;
	len_of_base = (long long) ft_strlen(base);
	while (content != 0)
	{
		digit = base[content % len_of_base];
		*(buffer++) = digit;
		content = content / len_of_base;
	}
	ft_strrev(begg);
	tr->content = begg;
	tr->len = ft_strlen(begg);
}
