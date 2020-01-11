# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louregni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 00:46:56 by louregni          #+#    #+#              #
#    Updated: 2019/01/22 19:58:47 by louregni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FILES 
SRC_NAME = draw.c \
		   fdf.c \
		   ft_plot_line.c \
		   get_map.c \
		   get_values.c \
		   init_map.c \
		   init_pixel_cord.c \
		   init_window.c \
		   key_manager.c \
		   parse_map.c 

HEADER_NAME = dimension.h \
			  draw.h \
			  get_map.h \
			  get_values.h \
			  init_map.h \
			  key.h \
			  parse_map.h \
			  pixel.h \
			  plot.h \
			  window.h


# PATH
LIBFT_PATH = libft/
SRC_PATH = src/
INCLUDES_PATH = includes/
INCLUDES_LIBFT_PATH= $(LIBFT_PATH)includes/
OBJ_PATH = obj/

# ASSIGNATION
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
HEADER = $(addprefix $(INCLUDES_PATH),$(HEADER_NAME))

# COMPILATION
NAME = fdf 
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS= -I $(INCLUDES_PATH) -I $(INCLUDES_LIBFT_PATH)
		
# RULES
all: $(NAME)

libft:
	@make -C $(LIBFT_PATH) all
	@echo "\033[32mLibft : [OK]"

$(NAME): libft $(HEADER) $(OBJ)
	@$(CC) $(OBJ) $(CPPFLAGS) -L$(LIBFT_PATH) -lft -o $(NAME) \
	-I /usr/local/include -L /usr/local/lib -lmlx -framework \
	OpenGL -framework Appkit
	@echo "\033[32mFdF : [OK]"

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "\033[32mObject's : cleared !"

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@echo "\033[32mFdF : deleted !"

re: fclean all

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@ 
.PHONY: all clean fclean re libft
