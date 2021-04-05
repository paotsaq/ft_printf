/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:30:08 by apinto            #+#    #+#             */
/*   Updated: 2021/03/24 12:02:01 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int args, ...)
{
	int			i;
	int			min_value;
	int			current;
	va_list		valist;

	va_start(valist, args);
	i = -1;
	min_value = INT_MIN;
	while (++i < args)
	{
		current = va_arg(valist, int);
		if (min_value > current || min_value == INT_MIN)
			min_value = current;
	}
	va_end(valist);
	return (min_value);
}
