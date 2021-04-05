/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:29:40 by apinto            #+#    #+#             */
/*   Updated: 2021/03/24 12:00:47 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int args, ...)
{
	int			i;
	int			max_value;
	int			current;
	va_list		valist;

	va_start(valist, args);
	i = -1;
	max_value = INT_MAX;
	while (++i < args)
	{
		current = va_arg(valist, int);
		if (max_value < current || max_value == INT_MAX)
			max_value = current;
	}
	va_end(valist);
	return (max_value);
}
