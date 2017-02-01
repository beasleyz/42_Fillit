/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:06:37 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/06 13:11:52 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	int x;
	int y;

	x = (int)ft_strlen(dst);
	y = (int)size - x - 1;
	if ((int)size < x)
		return (size + ft_strlen(src));
	while (y > 0 && *src)
	{
		dst[x] = *src++;
		x++;
		y--;
	}
	dst[x] = '\0';
	return (ft_strlen(src) + ft_strlen(dst));
}
