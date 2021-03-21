/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_base_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:27:09 by apinto            #+#    #+#             */
/*   Updated: 2021/03/21 10:32:25 by apinto           ###   ########.fr       */
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

	res = ft_calloc(20, sizeof(char));
	if (!res)
		return;
	len_of_base = strlen(base);
	if (tr->content < 0)
		tr->negative = 1;
	if (tr->content < 0)
		tr->content *= -1;
	while (tr->content != 0)
	{
		digit = base[(int)tr->content % len_of_base] + '0';
		*(res++) = digit;
		(int)tr->content /= len_of_base;
	}
	res = ft_reallocates_memory(strrev(res), strlen(res), 1, 0);
}


int		main()
{
	t_info	tr;

	initializes_tr(&tr);
	// missing initialization of params
	tr.content = 1234;
	tr.base = 10;
	str = ft_putnbr_base(&tr, DEC_BASE);
	fprintf("%d\n", str);
	free(str);
	str = ft_putnbr_base(1234, "0123456789abcdef");
	fprintf("%d\n", str);
	free(str);
}
