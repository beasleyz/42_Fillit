/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 23:23:11 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/03 23:23:13 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char*)malloc(sizeof(*s1) * ((int)ft_strlen(s1) + 1));
	if (!tmp)
		return (NULL);
	while (i < (int)ft_strlen(s1))
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
