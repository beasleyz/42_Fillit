/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:10:32 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/04 19:10:33 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned char *tempdst;
	unsigned char *tempsrc;

	tempdst = (unsigned char *)dst;
	tempsrc = (unsigned char *)src;
	while (n--)
		*tempdst++ = *tempsrc++;
	return (dst);
}
