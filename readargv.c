/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readargv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:35:42 by cdavila           #+#    #+#             */
/*   Updated: 2016/12/15 15:38:55 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		ft_buflen(char *ar1)
{
	char	buf;
	int		fd;
	int		count;

	count = 0;
	fd = open(ar1, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &buf, 1) != 0)
		count++;
	close(fd);
	return (count);
}

char	*readargv(char *ar1)
{
	char	buf;
	char	*str;
	int		fd;
	int		i;

	i = 0;
	str = ft_strnew(ft_buflen(ar1));
	fd = open(ar1, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &buf, 1) != 0)
	{
		str[i] = buf;
		i++;
	}
	str[i] = 0;
	close(fd);
	return (str);
}

int		ft_blocks(char *str)
{
	int blocks;
	int i;
	int rows;

	blocks = 1;
	i = 0;
	rows = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			rows++;
		if (str[i] == '\n' && str[i + 1] == '\n' && rows % 16 == 0)
			blocks++;
		i++;
	}
	return (blocks);
}

char	*str_shape(char *ar1)
{
	char	buf;
	char	*str;
	int		fd;
	int		i;

	i = 0;
	if (!checkall(ar1))
		return (NULL);
	str = ft_strnew(ft_blocks(readargv(ar1)) * 16);
	fd = open(ar1, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &buf, 1) != 0)
	{
		if (valid_char(buf) == FALSE)
			return (NULL);
		if (buf != '\n')
		{
			str[i] = buf;
			i++;
		}
	}
	close(fd);
	return (str);
}

char	**convert_str(char *str, int blocks)
{
	char	**astr;
	int		i;
	int		a;
	int		j;

	i = 0;
	a = 0;
	astr = ft_twoarray(blocks);
	while (i < blocks)
	{
		j = 0;
		astr[i] = ft_strnew(16);
		while (j < 16)
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
