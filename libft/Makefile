# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louregni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 10:27:19 by louregni          #+#    #+#              #
#    Updated: 2018/11/20 15:29:45 by louregni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_putchar.c\
		ft_putstr.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isdigit.c\
		ft_putchar.c\
		ft_strcmp.c\
		ft_strdup.c\
		ft_strncpy.c\
		ft_isascii.c\
		ft_isalpha.c\
		ft_isprint.c\
		ft_putstr.c\
		ft_strcpy.c\
		ft_strlen.c\
		ft_putendl_fd.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl.c\
		ft_putnbr_fd.c\
		ft_putnbr.c\
		ft_atoi.c\
		ft_strncmp.c\
		ft_memset.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnstr.c\
		ft_itoa.c\
		ft_ptrclr.c\
		ft_strsep.c\
		ft_strsplit.c\
		ft_memdup.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_isbetween.c\
		ft_strchg.c\
	
OBJ = $(SRC:.c=.o)

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

all:	$(NAME)

$(NAME): $(OBJ) libft.h
	ar rc $(NAME) $(OBJ) 
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all

.PHONY: all clean fclean re
