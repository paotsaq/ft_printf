/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:42:22 by apinto            #+#    #+#             */
/*   Updated: 2021/04/05 13:31:11 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_isspace(int chr)
{
	return (chr == 9 || chr == 10 || chr == 11
		|| chr == 12 || chr == 13 || chr == 0 || chr == ' ');
}

static	int	ft_issign(char chr)
{
	return (chr == '-' || chr == '+');
}

static	int	ft_isdigit(char chr)
{
	return (chr >= '0' && chr <= '9');
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (ft_issign(*str))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = 0;
	while (ft_isdigit(*str))
		res = res * 10 + (*(str++) - 48);
	return (res * sign);
}
