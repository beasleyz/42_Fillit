/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:49:22 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/03 09:49:24 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t len)
{
	int x;

	x = 0;
	while (len > 0 && src[x])
	{
		dst[x] = src[x];
		len--;
		x++;
	}
	while (len > 0)
	{
		dst[x] = '\0';
		x++;
		len--;
	}
	return (dst);
}
