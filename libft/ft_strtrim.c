/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 22:34:58 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/16 22:34:59 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space_bef(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static int	ft_space_aft(char const *s)
{
	int len;

	len = (int)ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	return (len);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*new;

	if (!s)
		return (NULL);
	i = ft_space_bef(s);
	len = ft_space_aft(s);
	if (len == 0)
		return (ft_strnew((size_t)len));
	new = ft_strnew((size_t)(len - i));
	if (!new)
		return (NULL);
	ft_strncpy(new, &s[i], len - i);
	new[len - i] = '\0';
	return (new);
}
