# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louregni <louregni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 23:46:46 by louregni          #+#    #+#              #
#    Updated: 2019/06/23 02:54:32 by louregni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GLOBAL

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = fractol

# SOURCES 

SRC := fractol.c render.c event.c fractal.c init.c thread.c color.c draw.c\
	   bind.c gesture.c mandelbrot.c

# PATH

SRC_PATH := src
FRACTOL_PATH := fractol
HEADER_PATH = header
INCLUDE = -I$(HEADER_PATH) -I$(SRC_PATH)/minilibx/
OBJ_PATH = obj

LIB = -L$(SRC_PATH)/minilibx/ -lmlx -framework OpenGL -framework AppKit
LIB += -lpthread -D_REENTRANT -lm

# LINK

SRC := $(addprefix $(FRACTOL_PATH)/,$(SRC))

# OBJECTS AND DEPENDENCY

OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)
DEP = $(OBJ:%.o=%.d)

# RULES

.PHONY: all
all: 
	@echo "\033[32mFlag compilation : \033[36m$(CFLAGS)"
	@echo "\033[32mMiniLibx compilation :\033[0m"
	@$(MAKE) -C $(SRC_PATH)/minilibx
	@echo "\033[32mGenerating objects :\033[0m"
	@$(MAKE) $(NAME)

$(NAME): $(OBJ) 
	@echo "\033[34mGenerated : \033[5;36m$(NAME)\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDE) $(LIB) $^ -o $@

-include $(DEP)
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -MMD -c $< -o $@
	@echo "\033[1;31m  >>  \033[4;34m$@\033[0m"

.PHONY: clean
clean:
	@$(MAKE) -C $(SRC_PATH)/minilibx/ clean
	@echo "\033[1;31mObject's removed\033[0m"
	@rm -rf $(OBJ_PATH)

.PHONY: fclean
fclean:
	@echo "\033[1;31m$(NAME) removed\033[0m"
	@$(MAKE) clean
	@rm -rf $(NAME)

.PHONY: re
re:
	@$(MAKE) fclean
	@$(MAKE) all
