# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdavila <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 17:43:43 by cdavila           #+#    #+#              #
#    Updated: 2016/12/08 17:43:44 by cdavila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

INCL = -I./fillit.h

RM = /bin/rm -f

LIBFT = libft.a

LDFLAGS = -L./libft/

LDLIBS = -lft

SRC = fillitmain.c checkfile.c readargv.c match_shape.c place_tet.c

OBJT = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C ./libft

$(OBJT):
	gcc -Wall -Wextra -Werror -c $(SRC)

$(NAME): $(OBJT) $(LIBFT)
	gcc -Wall -Wextra -Werror $(INCL) $(OBJT) -o $(NAME) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJT)
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re:	fclean all

.PHONY: all clean fclean re
