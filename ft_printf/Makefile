# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louregni <louregni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 00:46:56 by louregni          #+#    #+#              #
#    Updated: 2019/02/15 15:34:13 by louregni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FILES
SRC_NAME = ft_get_value.c ft_init_convert.c ft_init_modifier.c ft_printf.c \
		   ft_percent.c ft_print.c ft_color.c ft_get_double.c \

UTILS_NAME = ft_atoi_long.c ft_isdigit.c ft_isint.c \
			 ft_strlen.c ft_revert.c ft_get_base.c ft_set_va.c ft_ischar.c \
			 ft_isnumber.c ft_strncmp.c

PRINT_NAME = ft_str_number.c ft_fill.c ft_print_number.c ft_str_number_base.c \
			 ft_print_char.c ft_print_string.c ft_print_pointer.c \
			 ft_print_number_bases.c ft_print_double.c ft_str_double.c

PARSE_NAME = ft_check_dollar.c ft_check_flags.c ft_get_conv.c ft_get_format.c \
			 ft_get_precision.c ft_get_type.c ft_get_width.c ft_parser.c \

# INCLUDES_FOLDERS_NAME
STRUCTURES = structures
PROTOTYPES = prototypes
DEFINES = defines

# HEADERS NAME
STRUCTURES_NAME = s_format.h s_conversion.h s_modifier.h s_double.h s_print.h
DEFINES_NAME = d_info.h d_type.h d_flags.h
PROTOTYPES_NAME = p_chars.h p_color.h p_conversion.h p_create.h p_double.h \
				  p_fill.h p_get_format.h p_ischar.h p_modifier.h p_number.h \
				  p_parser.h p_percent.h p_print.h p_print_nbr.h \

# PATH
SRC_PATH = ./src/
UTILS_PATH = utils/
PARSER_PATH = parser/
PRINT_PATH = printer/
INCLUDES_PATH = ./includes/
OBJ_PATH = ./obj/

# ASSIGNATION SOURCES
SRC = $(SRC_NAME)
SRC += $(addprefix $(UTILS_PATH),$(UTILS_NAME))
SRC += $(addprefix $(PARSER_PATH),$(PARSE_NAME))
SRC += $(addprefix $(PRINT_PATH),$(PRINT_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(SRC:.c=.o))

# ASSIGNATION INCLUDES
STRUCT_PATH = $(addprefix $(INCLUDES_PATH),$(STRUCTURES)/)
DEFINE_PATH = $(addprefix $(INCLUDES_PATH),$(DEFINES)/)
PROTO_PATH = $(addprefix $(INCLUDES_PATH),$(PROTOTYPES)/)
INCLUDES = $(addprefix -I,$(STRUCT_PATH))
INCLUDES += $(addprefix -I,$(DEFINE_PATH))
INCLUDES += $(addprefix -I,$(PROTO_PATH))
HEADER = $(addprefix $(PROTO_PATH),$(PROTOTYPES_NAME))
HEADER += $(addprefix $(STRUCT_PATH),$(STRUCTURES_NAME))
HEADER += $(addprefix $(DEFINE_PATH),$(DEFINES_NAME))

# COMPILATION
NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -Werror -g

# RULES
all: $(NAME)

$(NAME): $(HEADER) $(OBJ)
	@ar rcs $@ $(OBJ)
	@echo "\033[32m$(NAME) generated with succes !\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)$(UTILS_PATH)
	@mkdir -p $(OBJ_PATH)$(PARSER_PATH)
	@mkdir -p $(OBJ_PATH)$(PRINT_PATH)
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)
	@echo "\033[32mObject's updateded : $@ !\033[0m"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[32mObject's removed with succes !\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mLibrary removed with succes !\033[0m"

re: fclean all

.PHONY: all clean fclean re
