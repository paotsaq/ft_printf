/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 05:13:12 by apinto            #+#    #+#             */
/*   Updated: 2021/03/30 15:35:52 by apinto           ###   ########.fr       */
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

	j = *i;
	while (str[j] && (ft_isdigit(str[j]) || str[j] == '*'))
		if (str[j] == '*' && !(tr->width || tr->w_aster))
		{
			tr->width = va_arg(*pargs, int);
			tr->w_aster = 1;
			tr->w_inp = 1;
			j++;
		}
		else if (ft_isdigit(str[j]) && !tr->w_aster)
		{
			tr->width = tr->width * 10 + str[j++] - '0';
			tr->w_inp = 1;
		}
	*i = j;
}

static	void	retrieves_prec(t_info *tr, char *str, int *i, va_list *pargs)
{
	int j;

	j = *i;
	if (str[j] && (str[j] == '.'))
	{
		if (str[j + 1] == '*' && !tr->prec)
		{
			tr->prec = va_arg(*pargs, int);
			tr->p_aster = 1;
			tr->p_inp = 1;
			j += 2;
		}
		else
		{
			while (ft_isdigit(str[++j]))
				tr->prec = tr->prec * 10 + str[j] - '0';
			tr->p_inp = 1;
		}
		if (!tr->p_inp)
			j++;
	}
	*i = j;
}

static	void	retrieves_type(t_info *tr, char *str, int *i, va_list *pargs)
{
	int j;
	int t;

	j = *i;
	t = -1;
	if (str[j])
	{
		while (TYPES[++t])
			if (str[j] == TYPES[t])
			{
				tr->type = str[j];
				if (ft_strchr("csp", tr->type))
					char_family_allocation(tr, pargs);
				else
					int_family_allocation(tr, pargs);
				break;
			}
	}
	if (!tr->type)
		tr->invalid = 1;
}

void			parses_string(t_info *tr, char *str, va_list *pargs)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			write(1, "%%", 2);
			i += 2;
		}
		else if (str[i] == '%')
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
