/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_base_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:27:09 by apinto            #+#    #+#             */
/*   Updated: 2021/03/22 05:22:30 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_family_allocation(t_info *tr, va_list *pargs)
{
	char *prov_str;

	if (tr->type == 'c')
	{
		(tr->content) = malloc(2 * sizeof(char));
		if (!tr->content)
			return;
		*(char *)(tr->content) = va_arg(*pargs, int);
	}
	else if (tr->type == 's')
	{
		*prov_str = va_arg(*pargs, int);
		(tr->content) = malloc(2 * strlen(prov_str));
		if (!tr->content)
			return;
		*(char *)(tr->content) = *prov_str;
	}
	// needs to be done!
	else if (tr->type == 'p')
		return;
}

void	int_family_allocation(t_info *tr, va_list *pargs)
{
	int				prov_number;
	unsigned int	number;

	if (tr->type == 'd' || tr->type == 'i')
	{
		prov_number = va_arg(*pargs, int);
		if (prov_number < 0)
		{
			tr->negative = 1;
			prov_number *= -1;
		}
		ft_putnbr_base(tr, (unsigned int)prov_number, DEC_BASE);
	}
	else
	{
		number = va_arg(*pargs, unsigned int);
		if (tr->type == 'u')
			ft_putnbr_base(tr, number, DEC_BASE);
		else
			ft_putnbr_base(tr, number, DEC_BASE);
	}
}

void	ft_putnbr_base(t_info *tr, unsigned int content, char *base)
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
	while (content != 0)
	{
		digit = base[content % len_of_base];
		*(res++) = digit;
		content = content / len_of_base;
	}
	res = ft_reallocates_memory(strrev(begg), strlen(begg), 1, 0);
	tr->content = begg;
}
