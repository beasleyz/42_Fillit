/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:36:21 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/14 18:36:23 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int a;

	a = (int)ft_strlen(s);
	if ((char)c == '\0')
	{
		return ((char *)&s[a]);
	}
	while (a > 0)
	{
		if (s[a - 1] == (char)c)
			return ((char *)&s[a - 1]);
		a--;
	}
	return (NULL);
}
