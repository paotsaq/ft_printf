/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:51:16 by apinto            #+#    #+#             */
/*   Updated: 2021/04/04 19:22:25 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initializes_info(t_info *info)
{
	info->zero = 0;
	info->minus = 0;
	info->width = 0;
	info->w_aster = 0;
	info->p_aster = 0;
	info->w_inp = 0;
	info->p_inp = 0;
	info->prec = 0;
	info->type = 0;
	info->chr = 0;
	info->content = 0;
	info->len = 0;
	info->negative = 0;
	info->invalid = 0;
}

void	char_family_allocation(t_info *info, va_list *pargs)
{
	if (ft_strchr("c%",info->type))
	{
		if (info->type == 'c')
			info->chr = va_arg(*pargs, int);
		else
			info->chr = '%';
		info->len = 1;
	}
	else if (info->type == 's')
	{
		(info->content) = va_arg(*pargs, char *);
		if (!(info->content))
			info->len = ft_strlen("(null)");
		else
			info->len = ft_strlen(info->content);
	}
	else if (info->type == 'p')
	{

	}
}

void	int_family_allocation(t_info *info, va_list *pargs, char *buffer)
{
	long long		prov_number;

	if (ft_strchr("diuxX", info->type))
	{
		prov_number = va_arg(*pargs, int);
		if (prov_number < 0)
		{
			info->negative = 1;
			prov_number *= -1;
		}
		ft_bzero(buffer, 12);
		if (ft_strchr("diu", info->type))
			number_to_string(info, prov_number, DEC_BASE, buffer);
		else
			number_to_string(info, prov_number, HEX_BASE, buffer);
	}
	else
	{
		prov_number = va_arg(*pargs, unsigned long long int);
		ft_strlcat(buffer, "0x", BUFF_LEN);
		number_to_string(info, prov_number, HEX_BASE, buffer);
	}
}
