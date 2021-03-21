/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_base_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:27:09 by apinto            #+#    #+#             */
/*   Updated: 2021/03/21 15:58:36 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*strrev(char *s1)
{
	char	swp;
	int		i;
	int		len;

	i = -1;
	len = strlen(s1);
	while (++i < len / 2)
	{
		swp = s1[i];
		s1[i] = s1[len - i - 1];
		s1[len - i - 1] = swp;
	}
	return (s1);
}

static void		ft_putnbr_base(t_info *tr, char *base)
{
	int			len_of_base;
	char		*res;
	char		digit;
	char		*begg;

	res = ft_calloc(20, sizeof(char));
	if (!res)
		return;
	begg = res;
	len_of_base = strlen(base);
	if (tr->content < 0)
		tr->negative = 1;
	if (tr->content < 0)
		*((int *)tr->content) *= -1;
	while (*(int *)tr->content != 0)
	{
		digit = base[*(int *)tr->content % len_of_base];
		*(res++) = digit;
		*((int *)tr->content) = *((int *)tr->content) / len_of_base;
	}
	res = ft_reallocates_memory(strrev(begg), strlen(begg), 1, 0);
	tr->content = begg;
}

// int		main()
// {
// 	t_info	tr;
// 	char 	*str;
// 	int		x;
// 
// 	initializes_tr(&tr);
// 	x = 1234;
// 	tr.content = &x;
// 	tr.base = 16;
// 	ft_putnbr_base(&tr, HEX_BASE);
// 	printf("%s\n", tr.content);
// }
