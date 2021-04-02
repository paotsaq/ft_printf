/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 05:13:12 by apinto            #+#    #+#             */
/*   Updated: 2021/04/02 05:49:30 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	retrieves_flags(t_info *info, char *str, int *i)
{
	int j;

	j = *i;
	while (str[j] && (str[j] == '-' || str[j] == '0'))
	{
		if (str[j] == '-')
			info->minus = 1;
		else
			info->zero = 1;
		j++;
	}
	*i = j;
}

static	void	retrieves_width(t_info *info, char *str, int *i, va_list *pargs)
{
	int j;

	j = *i;
	while (str[j] && (ft_isdigit(str[j]) || str[j] == '*'))
		if (str[j] == '*' && !(info->width || info->w_aster))
		{
			info->width = va_arg(*pargs, int);
			info->w_aster = 1;
			info->w_inp = 1;
			j++;
		}
		else if (ft_isdigit(str[j]) && !info->w_aster)
		{
			info->width = info->width * 10 + str[j++] - '0';
			info->w_inp = 1;
		}
	*i = j;
}

static	void	retrieves_prec(t_info *info, char *str, int *i, va_list *pargs)
{
	int j;

	j = *i;
	if (str[j] && (str[j] == '.'))
	{
		if (str[j + 1] == '*' && !info->prec)
		{
			info->prec = va_arg(*pargs, int);
			info->p_aster = 1;
			info->p_inp = 1;
			j += 2;
		}
		else
		{
			while (ft_isdigit(str[++j]))
				info->prec = info->prec * 10 + str[j] - '0';
			info->p_inp = 1;
		}
		if (!info->p_inp)
			j++;
	}
	*i = j;
}

static	void	retrieves_type(t_info *info, char *str, int *i)
{
	int j;
	int t;

	j = *i;
	t = -1;
	if (str[j])
		while (TYPES[++t])
			if (str[j] == TYPES[t])
				info->type = str[j];
}

void			handles_conversion(va_list *pargs, char *str, int *i)
{
	t_info	info;
	char	buffer[12];
	int		j;

	initializes_info(&info);
	j = *i;
	j++;
	retrieves_flags(&info, str, &j);
	retrieves_width(&info, str, &j, pargs);
	retrieves_prec(&info, str, &j, pargs);
	retrieves_type(&info, str, &j);
	*i = j;
	if (!info.type)
		printf("dude, come on\n");
	else if (ft_strchr("csp", info.type))
		char_family_allocation(&info, pargs);
	else
		int_family_allocation(&info, pargs, buffer);
	cleans_info_with_prios(&info);
	writes_buffer(&info);
}
