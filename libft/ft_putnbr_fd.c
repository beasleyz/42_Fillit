/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:48:25 by cdavila           #+#    #+#             */
/*   Updated: 2016/11/03 22:48:27 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nn;

	nn = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nn = -n;
	}
	if (nn / 10 > 0)
	{
		ft_putnbr_fd(nn / 10, fd);
	}
	ft_putchar_fd((nn % 10) + '0', fd);
}
