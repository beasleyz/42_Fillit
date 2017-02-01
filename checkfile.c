/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 19:23:08 by cdavila           #+#    #+#             */
/*   Updated: 2017/01/02 19:23:12 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

t_bool	valid_char(char c)
{
	if (c != '#' && c != '.' && c != '\n')
		return (FALSE);
	return (TRUE);
}

t_bool	ft_checkchar(char *str)
{
	int rows;
	int num;
	int lines;
	int blocks;

	rows = 0;
	num = 0;
	lines = 0;
	blocks = ft_blocks(str);
	while (*str)
	{
		if (*str == '#')
			num++;
		if (*str != '\n')
			rows++;
		else if (*str == '\n')
			lines++;
		str++;
	}
	if (rows % 16 != 0 || num % 4 != 0 || (lines != blocks * 5 - 1)
		|| rows / 16 != num / 4)
		return (FALSE);
	return (TRUE);
}

t_bool	checkall(char *str)
{
	int buflen;

	buflen = ft_buflen(str);
	if (ft_blocks(readargv(str)) == 0 || ft_blocks(readargv(str)) > 26
		|| !ft_checkchar(readargv(str)))
		return (FALSE);
	return (TRUE);
}

void	assign(t_point *size)
{
	size->min_i = 3;
	size->min_j = 3;
	size->max_i = 0;
	size->max_j = 0;
}
