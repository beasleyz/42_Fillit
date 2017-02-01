/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:04:14 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/02 16:04:15 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *s)
{
	int value;
	int i;
	int neg;

	i = 0;
	value = 0;
	neg = 1;
	while (ft_isspace(s[i]) == 1)
		i++;
	if ((s[i] == '+' && s[i + 1] == '-') || (s[i] == '-' && s[i + 1] == '+'))
		return (0);
	if (s[i] == '-')
	{
		neg = -1 * neg;
		i++;
	}
	if (s[i] == '+')
		i++;
	while (ft_isdigit(s[i]) == 1)
	{
		value = value * 10 + s[i] - '0';
		i++;
	}
	return (neg * value);
}
