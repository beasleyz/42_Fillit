/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:29:31 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/04 21:29:34 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	unsigned char *tempdst;
	unsigned char *tempsrc;

	tempdst = (unsigned char *)dst;
	tempsrc = (unsigned char *)src;
	while (n--)
	{
		if (*tempsrc == (unsigned char)c)
		{
			*tempdst = *tempsrc;
			return (++tempdst);
		}
		*tempdst++ = *tempsrc++;
	}
	return (NULL);
}
