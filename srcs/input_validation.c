/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 08:30:43 by apinto            #+#    #+#             */
/*   Updated: 2021/03/21 05:45:40 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (tr->zero && (flag_of(tr->type) >> 0 & 0 || tr->minus))
		tr->zero = 0;
	if (tr->prec && (prec < len) && (flag_of(tr->type) >> 1) & 1)
	{
		temp = tr->content;
		tr->content = ft_reallocates_memory(temp, tr->prec, 1, 0);
		free(temp);
	}
}
