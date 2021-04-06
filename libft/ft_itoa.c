/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 06:02:14 by apinto            #+#    #+#             */
/*   Updated: 2021/04/05 13:28:24 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*strrev(char *s1)
{
	char	swp;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(s1);
	while (++i < len / 2)
	{
		swp = s1[i];
		s1[i] = s1[len - i - 1];
		s1[len - i - 1] = swp;
	}
	return (s1);
}

static	int	number_of_chars(int n)
{
	int	i;
	int	sign;

	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	else
		sign = 0;
	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i + sign);
}

static	char	*handle_negatives(char *iter, int *n)
{
	if (*n == -2147483648)
	{
		ft_memset(iter++, '8', 1);
		*n = 214748364;
	}
	else
		*n *= -1;
	return (iter);
}

static	char	*check_sign(char *iter, int sign)
{
	if (sign == -1)
		ft_memset(iter++, '-', 1);
	return (iter);
}

char	*ft_itoa(int n)
{
	char	*res;
	char	*iter;
	int		sign;

	res = ft_calloc(number_of_chars(n) + 1, sizeof(char));
	if (!res)
		return (0);
	sign = 1;
	iter = res;
	if (n == 0)
		ft_memset(iter++, '0', 1);
	if (n < 0)
	{
		iter = handle_negatives(iter, &n);
		sign = -1;
	}
	while (n != 0)
	{
		ft_memset(iter++, (char)(n % 10) + '0', 1);
		n /= 10;
	}
	iter = check_sign(iter, sign);
	ft_memset(iter++, 0, 1);
	strrev(res);
	return (res);
}
