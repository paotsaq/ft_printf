/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:28:52 by apinto            #+#    #+#             */
/*   Updated: 2021/04/05 13:22:52 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sub(const char *haystack, const char *needle, int len)
{
	while (*needle && len-- && *(++needle) == *(++haystack))
		;
	return ((*needle) == '\0');
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && (int)len-- > 0)
	{
		if ((*haystack == *needle && check_sub(haystack, needle, len + 1)))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
