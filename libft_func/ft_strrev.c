/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42lisboa.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:51:26 by apinto            #+#    #+#             */
/*   Updated: 2021/03/24 12:04:07 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s1)
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
