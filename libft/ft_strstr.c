/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 22:36:34 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/08 22:36:35 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_lookstr(char const *big, char const *little)
{
	int	x;
	int	y;
	int len;

	x = 0;
	y = 0;
	len = 0;
	while (big[x])
	{
		if ((little[y] == big[x]) && little[y])
		{
			y++;
			x++;
			if (y == (int)ft_strlen(little))
				return ((char *)&big[x - y]);
		}
		else
		{
			len++;
			x = len;
			y = 0;
		}
	}
	return (NULL);
}

char		*ft_strstr(char const *big, char const *little)
{
	if (!*little)
		return ((char *)big);
	else if (!*big)
		return (NULL);
	return (ft_lookstr(big, little));
}
