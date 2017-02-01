/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 01:55:22 by cdavila           #+#    #+#             */
/*   Updated: 2017/01/10 01:55:24 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

char	*create_map(int width)
{
	char	*map;
	int		strlen;
	int		current;
	int		i;

	i = 0;
	current = width;
	strlen = (width + 1) * width;
	map = (char*)malloc(sizeof(char) * (strlen + 1));
	if (!map)
		return (NULL);
	while (i < strlen)
	{
		if (i == width || i == (current + width + 1))
		{
			map[i] = '\n';
			current = i;
		}
		else
			map[i] = '.';
		i++;
	}
	map[strlen] = '\0';
	return (map);
}

int		index_of(char *tet, char *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tet[i] == '.')
		i++;
	while (map[j] != '\0')
	{
		if (map[j] == tet[i] && tet[i] != '\n')
			return (j - i);
		j++;
	}
	return (0);
}

int		check_valid(char *tet, char *map, int r)
{
	int i;
	int count;
	int j;

	i = 0;
	j = 0;
	count = 0;
	if (map[r] == '\n' && map[r] != '\0')
		return (0);
	while (map[i + r] != '\0' && tet[j] != '\0')
	{
		if (map[i + r] == '\n' && tet[j] != '\n')
			return (0);
		while (tet[j] == '\n' && map[i] != '\n')
			i++;
		if (map[i + r] == '.' && tet[j] != '.' && tet[j] != '\n')
			count++;
		if (count == 4)
			return (1);
		j++;
		i++;
	}
	if (map[i + r] == '\0')
		return (2);
	return (0);
}

char	*remove_tet(char *tet, char *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tet[i] == '.')
		i++;
	while (map[j] != '\0')
	{
		if (map[j] == tet[i])
			map[j] = '.';
		j++;
	}
	return (map);
}

char	*place_tet(char *tet, char *map, int r)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tet[j] != '\0')
	{
		if (tet[j] != '\n' && (map[i + r] == '.' || map[i + r] == tet[j]))
			map[i + r] = tet[j];
		while (tet[j] == '\n' && map[i] != '\n')
			i++;
		i++;
		j++;
	}
	return (map);
}
