/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 05:13:12 by apinto            #+#    #+#             */
/*   Updated: 2021/03/24 04:31:39 by apinto           ###   ########.fr       */
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
	if (str[j] && (str[j] == '.'))
	{
		if (str[j + 1] == '*' && !tr->prec)
		{
			prov = va_arg(*pargs, int);
			tr->prec = prov;
			tr->p_aster = 1;
			// negative prec and width cases are still missing!
			j += 2;
		}
		else if (str[j] == '.' && !tr->p_aster)
			while (ft_isdigit(str[++j]))
				tr->prec = tr->prec * 10 + str[j] - '0';
		else
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
	t = -1;
	if (str[j])
	{
		while (TYPES[++t])
			if (str[j] == TYPES[t])
			{
				tr->type = str[j];
				if (strchr("csp", tr->type))
					char_family_allocation(tr, pargs);
				else
					int_family_allocation(tr, pargs);
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
