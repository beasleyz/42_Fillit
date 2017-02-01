/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:48:30 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/05 11:48:32 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	unsigned char *tempdst;
	unsigned char *tempsrc;

	tempdst = (unsigned char *)dst;
	tempsrc = (unsigned char *)src;
	if (dst <= src)
	{
		while (len--)
			*tempdst++ = *tempsrc++;
	}
	else
	{
		tempdst += len;
		tempsrc += len;
		while (len--)
			*--tempdst = *--tempsrc;
	}
	return (dst);
}
