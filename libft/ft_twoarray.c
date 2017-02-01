/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twoarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 21:11:05 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/20 21:11:06 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_twoarray(size_t size)
{
	char	**str;

	str = (char**)malloc(sizeof(char*) * (size + 1));
	if (!str)
		return (NULL);
	return (str);
}
