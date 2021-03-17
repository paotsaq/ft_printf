/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 04:29:16 by apinto            #+#    #+#             */
/*   Updated: 2021/03/17 10:46:15 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initializes_tr(t_flags *tr)
{
	tr->zero = 0;
	tr->minus = 0;
	tr->width = 0;
	tr->w_aster = 0;
	tr->p_aster = 0;
	tr->prec = 0;
	tr->invalid = 0;
}

void	checks_flags(t_flags *tr, char *str, int *i)
{
	int j;

	j = *i;
	while (str[j] && (str[j] == '-' || str[j] == '0') && !tr->invalid)
	{
		if (str[j] == '-')
			tr->minus = 1;
		else
			tr->zero = 1;
		if (tr->minus + tr->zero > 1)
			tr->invalid = 1;
		j++;
	}
	*i = j;
	// I might return something if needed 
}

void	checks_width(t_flags *tr, char *str, int *i, va_list *pargs)
{
	int j;
	int prov;

	j = *i;
	while (str[j] && (ft_isdigit(str[j]) || str[j] == '*') && !tr->invalid)
	{
		if (str[j] == '*' && !(tr->width || tr->w_aster))
		{
			prov = va_arg(*pargs, int);
			tr->width = prov;
			tr->w_aster = 1;
			j++;
		}
		else if (ft_isdigit(str[j]) && !tr->w_aster)
		{
			tr->width = tr->width * 10 + str[j];
			j++;
		}
	}
	*i = j;
}

void	checks_prec(t_flags *tr, char *str, int *i, va_list *pargs)
{
	int j;
	int prov;

	j = *i;
	while (str[j] && (str[j] == '.' || str[j] == '*') && !tr->invalid)
		if (str[j] == '*' && !tr->prec)
		{
			prov = va_arg(*pargs, int);
			tr->width = prov;
			tr->w_aster = 1;
			j++;
		}
		else if (str[j] == '.' && !tr->p_aster)
			while (ft_isdigit(str[j]))
			{
				tr->prec = tr->prec * 10 + str[j];
				j++;
			}
	*i = j;
}

void	checks_type(t_flags *tr, char *str, int *i, va_list *pargs)
{
	int j;
	int t;
	int prov;

	j = i*
	if (!tr->invalid && str[j])
	{
		prov = va_arg(*pargs, int);
		t = -1;
		while (types[++t])
			if (ft_strchr(types[t], prov))
				tr->type = prov;
	}
	if *(!tr->type)
		tr->invalid = 1;
}
