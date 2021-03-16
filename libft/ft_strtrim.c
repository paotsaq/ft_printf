/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 04:07:54 by apinto            #+#    #+#             */
/*   Updated: 2021/02/22 18:23:13 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_set(const char *s1, char const *set, int i, int step)
{
	int			accum;
	char const	*set_begg;

	accum = 0;
	set_begg = set;
	while (s1[i] && *set)
	{
		if (*set == s1[i])
		{
			accum++;
			set = set_begg;
			i += step;
		}
		else
			set++;
	}
	return (accum);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		begg;
	int		end;
	int		size;
	char	*res;

	if (!s1)
		return (0);
	begg = check_set(s1, set, 0, 1);
	if (begg == (int)ft_strlen(s1))
		return (ft_calloc(sizeof(char), 1));
	end = check_set(s1, set, ft_strlen(s1) - 1, -1);
	size = ft_strlen(s1) - begg - end + 1;
	res = ft_calloc(sizeof(char), size);
	if (res)
		ft_strlcat(res, s1 + begg, size);
	return (res);
}
