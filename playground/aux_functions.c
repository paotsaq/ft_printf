/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 04:29:16 by apinto            #+#    #+#             */
/*   Updated: 2021/03/16 05:57:01 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initializes_tr(t_flags *tr)
{
	tr.zero = 0;
	tr.minus = 0;
	tr.width = 0;
	tr.w_aster = 0;
	tr.prec = 0;
	tr.invalid = 0;
}

int		checks_flags(t_flags *tr, char *str, int *i)
{
	while (str[j] && has_flags(str[j]) > 0 && !tr.invalid)
	{
		if (has_flags(str[j]) == 1)
			tr.minus = 1;
		else
			if (tr.minus)
				tr.invalid = 1;
			else
				tr.zero = 1;
		j++;
	}
}

int		checks_width(t_flags *tr, char *str, int *i)
{
	while (str[j] && (is_digit(str[j]) || str[j] == '*') && !tr.invalid)
		if (str[j] == '*' && !(tr.width || tr.w_aster))
			// take va.arg
			tr.aster = 1;
		else if (is_digit(str[j]) && !tr.aster)
			tr.width = tr.width * 10 + str[j];
		// jumping the gun?
		else
			tr.invalid = 1;
}

int		checks_prec(t_flags *tr, char *str, int *i)
{
	while (str[j] && (str[j] == '.' || str[j] == '*') && !tr.invalid)
		if (str[j] == '*')
			// take va.arg
		else if (str[j] == '.')
			while (is_digit(str[++j]))
				tr.prec = tr.prec * 10 + str[j];
}

int		has_flags(char c)
{
	if (c == '-')
		return (1);
	else if (c == '0')
		return (2);
	else
		return (0);
}

