/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:09:53 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/17 16:09:54 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counting(char const *s, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	count_letters(char *s, char c)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	*location(char *s, char c)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (&s[i - len]);
}

static char	**split(char const *s, char c, int words)
{
	char	**arry;
	int		i;
	int		len;
	char	*tmp;

	arry = (char**)malloc(sizeof(char*) * (size_t)(words + 1));
	if (!arry)
		return (NULL);
	i = 0;
	len = 0;
	tmp = ft_strdup(s);
	while (words--)
	{
		tmp = location(&tmp[len], c);
		len = count_letters(tmp, c);
		arry[i] = ft_strnew((size_t)len);
		ft_strncpy(arry[i], tmp, len);
		arry[i][len] = '\0';
		i++;
	}
	arry[i] = NULL;
	return (arry);
}

char		**ft_strsplit(char const *s, char c)
{
	int words;

	if (!s)
		return (NULL);
	words = counting(s, c);
	return (split(s, c, words));
}
