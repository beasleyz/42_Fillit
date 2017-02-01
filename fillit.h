/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdavila <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 12:07:12 by cdavila           #+#    #+#             */
/*   Updated: 2016/12/10 12:07:16 by cdavila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ERROR	"error\n"
# define USAGE	"usage fillit input_file\n"
# define TRUE		1
# define FALSE		0

typedef int		t_bool;

typedef struct	s_point
{
	int max_i;
	int min_i;
	int max_j;
	int min_j;
}				t_point;

int				ft_buflen(char *ar1);
char			*readargv(char *ar1);
int				ft_blocks(char *str);
char			*str_shape(char *ar1);
char			**convert_str(char *str, int blocks);

t_bool			valid_char(char c);
t_bool			ft_checkchar(char *str);
t_bool			checkall(char *str);
void			assign(t_point *size);

char			**matrix(char *str);
int				valid_shape(char **astr);
t_point			size(char **shp);
char			letter(char shape, int index);
char			*final(char **shp, int index, t_point size);

char			*create_map(int width);
int				index_of(char *tet, char *map);
int				check_valid(char *tet, char *map, int r);
char			*remove_tet(char *tet, char *map);
char			*place_tet(char *tet, char *map, int r);

char			**check_shape(char **a, int blocks);
int				nbr(int blocks);
char			*fillit(char **tet, char *map, int i, int size);

#endif
