/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 21:16:04 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/13 21:16:07 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlencmp(char const *s1, char const *s2, size_t l1, size_t l2)
{
	while ((*s1 == *s2) && (l1 > 0) && *s2 && (l2 > 0))
	{
		l1--;
		l2--;
		s1++;
		s2++;
	}
	if (l1 == 0)
		return (0);
	return (1);
}

static char	*ft_looknstr(char const *big, char const *little, size_t len)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (big[x] && (int)len > 0)
	{
		if (ft_strlencmp(little, &big[x], ft_strlen(little), len) == 0)
			return ((char *)&big[x]);
		else
		{
			y++;
			x = y;
		}
		len--;
	}
	return (NULL);
}

char		*ft_strnstr(char const *big, char const *little, size_t len)
{
	if (!*little)
		return ((char *)big);
	else if (!*big)
		return (NULL);
	return (ft_looknstr(big, little, len));
}
