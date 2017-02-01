/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 21:57:52 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/07 21:57:53 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isprime(int a, int i)
{
	while ((a - i) > 2)
	{
		if (a == 2)
			return (TRUE);
		else if (a % 2 == 0)
			return (FALSE);
		else if (a % (a - i) == 0)
			return (FALSE);
		else if (a % (a - i) != 0)
		{
			i++;
			return (ft_isprime(a, i));
		}
	}
	return (TRUE);
}
