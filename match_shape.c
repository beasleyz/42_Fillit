/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matching.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 20:29:59 by cdavila           #+#    #+#             */
/*   Updated: 2017/01/02 20:30:01 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

char	**matrix(char *str)
{
	int		i;
	int		j;
	char	**astr;
	int		a;

	i = 0;
	a = 0;
	astr = ft_twoarray(4);
	while (i < 4)
	{
		j = 0;
		astr[i] = ft_strnew(4);
		while (j < 4)
		{
			astr[i][j] = str[a];
			j++;
			a++;
		}
		astr[i][j] = '\0';
		i++;
	}
	astr[i] = 0;
	return (astr);
}

int		valid_shape(char **astr)
{
	int count;
	int j;
	int i;

	count = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i > 0 && (astr[i][j] == '#' && astr[i - 1][j] == '#'))
				count++;
			if (j > 0 && (astr[i][j] == '#' && astr[i][j - 1] == '#'))
				count++;
			if (j < 3 && (astr[i][j] == '#' && astr[i][j + 1] == '#'))
				count++;
			if (i < 3 && (astr[i][j] == '#' && astr[i + 1][j] == '#'))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_point	size(char **shp)
{
	t_point size;
	int		i;
	int		j;

	assign(&size);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (shp[i][j] == '#' && i < size.min_i)
				size.min_i = i;
			if (shp[i][j] == '#' && j < size.min_j)
				size.min_j = j;
			if (shp[i][j] == '#' && i > size.max_i)
				size.max_i = i;
			if (shp[i][j] == '#' && j > size.max_j)
				size.max_j = j;
			j++;
		}
		i++;
	}
	return (size);
}

char	letter(char shape, int index)
{
	char letter;

	if (shape == '#')
		letter = 17 + index + '0';
	else
		letter = '.';
	return (letter);
}

char	*final(char **shp, int index, t_point size)
{
	char	*final;
	int		a;
	int		b;
	int		i;

	a = size.min_i;
	i = 0;
	final = ft_strnew(8);
	while (a < size.max_i + 1)
	{
		b = size.min_j;
		while (b < size.max_j + 1)
		{
			final[i] = letter(shp[a][b], index);
			b++;
			i++;
		}
		(a < size.max_i) ? final[i] = '\n' : 0;
		(a < size.max_i) ? i++ : 0;
		a++;
	}
	final[i] = '\0';
	return (final);
}
