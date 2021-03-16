/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 04:45:06 by apinto            #+#    #+#             */
/*   Updated: 2021/03/16 05:57:16 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(int argc, char **argv)
{
	char 	*str;
	int 	i;
	int 	j;
	t_flags	tr;

	i = -1;
	// initializes tr
	initializes_tr(tr);
	while (str[++i])
		if (str[i] == '%')
		{
			i++;
			checks_flags(&tr, &str[i], &i);
			// both missing va arg!
			checks_width(&tr, &str[i], &i);
			checks_prec(&tr, &str[i], &i);
		}
}
