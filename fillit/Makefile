# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louregni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 10:27:19 by louregni          #+#    #+#              #
#    Updated: 2018/12/07 17:32:44 by louregni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit
SRC =	fillit.c finit.c ft_check_l.c ft_check_line.c ft_check_s.c main.c \
	ft_check_sqr.c ft_check_t.c ft_face_l.c ft_face_l2.c ft_face_line.c \
	ft_face_s.c ft_face_sqr.c ft_face_t.c ft_isplaceable.c 

LIBPATH = libft
LIBNAME = ft
HEADER = check.h fillit.h finit.h search.h libft/libft.h

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS  = -Wall -Wextra -Werror 
CPPFLAGS = -I $(LIBPATH)
EXT = -L $(LIBPATH) -l $(LIBNAME)
RM = rm -f

all: $(NAME)

dependence:
	@make -C $(LIBPATH) all
	@echo "\033[32m[OK] : \033[0;36mCreation Libft\033[0m"

$(NAME): dependence $(OBJ) $(HEADER)
	@echo "\033[32m[OK] : \033[0;36mCreation objects\033[0m"
	@$(CC) $(SRC) $(EXT) $(CPPFLAGS) -o $(NAME)
	@echo "\033[32m[OK] : \033[0;36mCreation executable\033[0m"


clean:
	@make -C $(LIBPATH) clean
	@echo "\033[32m[OK] : \033[0;36mLibft removed\033[0m"
	@$(RM) $(OBJ) 
	@echo "\033[32m[OK] : \033[0;36mObjects removed\033[0m"

fclean:	clean
	@make -C $(LIBPATH) fclean
	@$(RM) $(NAME)
	@echo "\033[32m[OK] : \033[0;36mExecutable removed\033[0m"

re:	fclean	all

%.o: %.c
	@$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

.PHONY: all clean fclean re
