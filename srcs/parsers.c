/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 05:13:12 by apinto            #+#    #+#             */
/*   Updated: 2021/03/21 13:38:56 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	retrieves_flags(t_info *tr, char *str, int *i)
{
	int j;

	j = *i;
	while (str[j] && (str[j] == '-' || str[j] == '0'))
	{
		if (str[j] == '-')
			tr->minus = 1;
		else
			tr->zero = 1;
		j++;
	}
	*i = j;
}

static	void	retrieves_width(t_info *tr, char *str, int *i, va_list *pargs)
{
	int j;
	int prov;

	j = *i;
	while (str[j] && (ft_isdigit(str[j]) || str[j] == '*'))
		if (str[j] == '*' && !(tr->width || tr->w_aster))
		{
			prov = va_arg(*pargs, int);
			tr->width = prov;
			tr->w_aster = 1;
			j++;
		}
		else if (ft_isdigit(str[j]) && !tr->w_aster)
		{
			tr->width = tr->width * 10 + str[j] - '0';
			j++;
		}
	*i = j;
}

static	void	retrieves_prec(t_info *tr, char *str, int *i, va_list *pargs)
{
	int j;
	int prov;

	j = *i;
	while (str[j] && (str[j] == '.'))
	{
		if (str[j + 1] == '*' && !tr->prec)
		{
			prov = va_arg(*pargs, int);
			tr->prec = prov;
			tr->p_aster = 1;
			j++;
		}
		else if (str[j] == '.' && !tr->p_aster)
			while (ft_isdigit(str[++j]))
				tr->prec = tr->prec * 10 + str[j] - '0';
		j++;
	}
	*i = j;
}

static	void	retrieves_type(t_info *tr, char *str, int *i, va_list *pargs)
{
	int j;
	int t;
	int prov;

	j = *i;
	if (str[j])
	{
		prov = va_arg(*pargs, int);
		t = -1;
		while (TYPES[++t])
			if (ft_strchr(&TYPES[t], prov))
				tr->type = prov;
	}
}

void			parses_string(t_info *tr, char *str, va_list *pargs)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			retrieves_flags(tr, str, &i);
			retrieves_width(tr, str, &i, pargs);
			retrieves_prec(tr, str, &i, pargs);
			retrieves_type(tr, str, &i, pargs);
		}
		// more conversions
	}
}
