/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:30:43 by apinto            #+#    #+#             */
/*   Updated: 2021/03/23 06:01:17 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 0bxy controls possible flags for each type.
 * x = zero flag (if 1, can apply)
 * y = precision (if 1, precision will trim)
 */
static	int		flag_info(char c)
{
	if (c == 'c' || c == 'p')
		return (0b00);
	else if (c == 's')
		return (0b01);
	else
		return (0b10);
}

void			cleans_info_with_prios(t_info *tr)
{
	void	*temp;

	// needs handling this case; should return?
	if (!strchr(TYPES, tr->type))
	{
		tr->invalid = 1;
		return;
	}
	if (tr->minus)
		tr->zero = 0;
	if (tr->type == 's' && tr->prec && (tr->prec < tr->len))
	{
		temp = tr->content;
		tr->content = ft_reallocates_memory(temp, tr->prec + 1, 1, 0);
		tr->len = tr->prec;
	}
	//if (tr->prec > tr->len && tr->type != 'c' && tr->type != 's')
	//	tr->width -= tr->prec - tr->len;
}
