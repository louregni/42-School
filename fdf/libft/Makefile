# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckillian <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 20:49:48 by ckillian          #+#    #+#              #
#    Updated: 2019/01/22 19:04:28 by louregni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstcount.c \
	  ft_sqrt.c \
	  ft_pow.c \
	  ft_factorial.c \
	  ft_lstremoveone.c \
	  ft_memdup.c \
	  ft_memjoin.c \
	  ft_strndup.c \
	  ft_strsep.c \
	  get_next_line.c \
	  ft_strlowercase.c \
	  ft_atoi_base.c \
	  ft_ptrclr.c \

OBJ = $(SRC:.c=.o)

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) includes/libft.h includes/get_next_line.h
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) -I includes/

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all
