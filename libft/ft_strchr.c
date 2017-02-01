/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:26:42 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/07 11:26:48 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	int a;

	a = 0;
	if ((char)c == '\0')
	{
		a = (int)ft_strlen(s);
		return ((char *)&s[a]);
	}
	while (s[a] != '\0')
	{
		if (s[a] == (char)c)
			return ((char *)&s[a]);
		a++;
	}
	return (NULL);
}
