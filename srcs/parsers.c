/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 05:13:12 by apinto            #+#    #+#             */
/*   Updated: 2021/04/05 03:28:25 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	retrieves_flags(t_info *info, char **str)
{
	while (ft_strchr("0-", **str))
	{
		if (**str == '-')
		{
			info->minus = 1;
			*(str) += 1;
		}
		else if (**str == '0')
		{
			info->zero = 1;
			*(str) += 1;
		}
	}
}

static	void	retrieves_width(t_info *info, char **str, va_list *pargs)
{
	while (str && (ft_isdigit(**str) || **str == '*'))
	{
		if (**str == '*' && !(info->width || info->w_aster))
		{
			info->width = va_arg(*pargs, int);
			info->w_aster = 1;
			info->w_inp = 1;
			*(str) += 1;
		}
		else if (!info->w_aster)
		{
			while (ft_isdigit(**str))
			{
				info->width = info->width * 10 + (int)**str - '0';
				*(str) += 1;
			}
			info->w_inp = 1;
		}
	}
}

static	void	retrieves_prec(t_info *info, char **str, va_list *pargs)
{
	if (str && (**str == '.'))
	{
		if (*(*(str) + 1) == '*' && !info->prec)
		{
			info->prec = va_arg(*pargs, int);
			info->p_aster = 1;
			info->p_inp = 1;
			*(str) += 2;
		}
		else
		{
			*(str) += 1;
			while (*str && ft_isdigit(**str))
			{
				info->prec = info->prec * 10 + (int)**str - '0';
				*(str) += 1;
			}
			info->p_inp = 1;
		}
		if (!info->p_inp)
			*(str) += 1;
	}
}

static	void	retrieves_type(t_info *info, char **str)
{
	int	i;

	i = -1;
	while (TYPES[++i] && str)
	{
		if (**str == TYPES[i] || **str == '%')
		{
			info->type = **str;
			return ;
		}
	}
	info->invalid = 1;
}

void	handles_conversion(va_list *pargs, char **str)
{
	t_info	info;
	char	*begg;
	char	buffer[BUFF_LEN];

	begg = *str;
	initializes_info(&info);
	retrieves_flags(&info, str);
	retrieves_width(&info, str, pargs);
	retrieves_prec(&info, str, pargs);
	retrieves_type(&info, str);
	if (info.invalid)
		writes_chars(begg - 1, *str);
	else
	{
		if (!info.type)
			info.content = 0;
		else if (ft_strchr("cs%", info.type))
			char_family_allocation(&info, pargs);
		else
			int_family_allocation(&info, pargs, buffer);
		cleans_info_with_prios(&info);
		writes_buffer(&info);
	}
}
