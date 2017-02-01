/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:47:53 by cdavila           #+#    #+#             */
/*   Updated: 2016/12/08 17:47:54 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

char	**check_shape(char **a, int blocks)
{
	char	**fnl;
	int		i;

	i = 0;
	fnl = ft_twoarray(blocks);
	while (i < blocks)
	{
		if (valid_shape(matrix(a[i])) == 6 || valid_shape(matrix(a[i])) == 8)
			fnl[i] = ft_strdup(final(matrix(a[i]), i, size(matrix(a[i]))));
		else
			return (NULL);
		i++;
	}
	fnl[i] = 0;
	return (fnl);
}

int		nbr(int blocks)
{
	int i;

	i = 1;
	while (blocks * 4 > i * i)
		i++;
	return (i);
}

char	*fillit(char **tet, char *map, int i, int size)
{
	int j;

	j = 0;
	while (tet[i] != NULL && check_valid(tet[i], map, j) != 2)
	{
		while (check_valid(tet[i], map, j) == 0)
			j++;
		if (check_valid(tet[i], map, j) == 1)
		{
			map = place_tet(tet[i], map, j);
			j = 0;
			i++;
			if (tet[i] == NULL)
				return (map);
		}
		if (check_valid(tet[i], map, j) == 2 && i != 0)
		{
			j = index_of(tet[i - 1], map) + 1;
			map = remove_tet(tet[i - 1], map);
			i--;
		}
	}
	if (check_valid(tet[i], map, j) == 2 && i == 0)
		map = fillit(tet, create_map(size + 1), 0, size + 1);
	return (map);
}

int		main(int argc, char **argv)
{
	int		blocks;
	char	**astr;
	char	**input;

	blocks = 0;
	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	if (!str_shape(argv[1]))
	{
		ft_putstr(ERROR);
		return (0);
	}
	blocks = ft_blocks(readargv(argv[1]));
	astr = convert_str(str_shape(argv[1]), blocks);
	if (!(input = check_shape(astr, blocks)))
	{
		ft_putstr(ERROR);
		return (0);
	}
	ft_putstr(fillit(input, create_map(nbr(blocks)), 0, nbr(blocks)));
	return (0);
}
