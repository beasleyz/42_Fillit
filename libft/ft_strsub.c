/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:19:36 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/16 21:46:33 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	substr = ft_strnew(len);
	if (!s)
		return (NULL);
	if (!substr)
		return (NULL);
	ft_strncpy(substr, &s[start], len);
	return (substr);
}
