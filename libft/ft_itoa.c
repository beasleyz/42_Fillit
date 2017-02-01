/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:56:37 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/08 14:56:38 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*iszero(int n)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(ft_len_int(n));
	if (!tmp)
		return (NULL);
	if (n == 0)
	{
		tmp[i] = '0';
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	*toarray(int n, int len)
{
	char			*tmp;
	int				i;
	unsigned int	nn;

	nn = n;
	i = 0;
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	if (n == 0)
		return (iszero(n));
	if (n < 0)
	{
		tmp[i] = '-';
		nn = -n;
		i++;
	}
	while (len > i)
	{
		tmp[len - 1] = (nn % 10) + '0';
		nn = nn / 10;
		len--;
	}
	tmp[ft_len_int(n)] = '\0';
	return (tmp);
}

char		*ft_itoa(int n)
{
	int len;

	len = ft_len_int(n);
	return (toarray(n, len));
}
