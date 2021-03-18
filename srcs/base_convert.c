/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:27:09 by apinto            #+#    #+#             */
/*   Updated: 2021/03/18 10:12:43 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_length(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	recursive_step(int nbr, char *base, char *src, int *i)
{
	int 	len_of_base;

	len_of_base = 0;
	if (nbr < len_of_base)
		write(1, &base[nbr], 1);
	else
	{
		recursive_step(nbr / len_of_base, base, len_of_base);
		write(1, &base[nbr % len_of_base - 1], 1);
	}
}

static void	ft_putnbr_base(int nbr, char *base, char *src, int *i)
{
	int 	len_of_base;
	char 	*res;
	int 	*i;

	i = 0;
	res = ft_calloc(1024, sizeof(char));
	if (!res)
		return (-1);
	len_of_base = ft_length(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= (-1);
	}
	if (len_of_base > 1)
		recursive_step(nbr, base, len_of_base);
}

int		main()
{
	str = ft_putnbr_base(0, "0123467");
	fprintf("%d\n", str);
	free(str);
	str = ft_putnbr_base(1234, "0123456789abcdef");
	fprintf("%d\n", str);
	free(str);
}
