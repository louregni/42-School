# SOURCES 

SRC_PARSER := parser.c parsing.c get.c find_newline.c get_name.c get.c \
			check.c get_node_name.c link.c node.c
SRC_LEM-IN := main.c free_functions.c graph_init.c algorithm.c \
			path_maker.c path_manager.c turns.c print.c free.c
SRC_UTILS := compare.c ft_memcpy.c ft_memalloc.c ft_strndup.c ft_bzero.c \
			ft_strncmp.c ft_itoa.c
SRC_BONUS := bonus.c print_bonus.c benchmark.c info.c

# PATH GLOBAL

SRC_PATH := src
OBJ_PATH := obj
HEADER_PATH := includes

# SRC TREE

PARSER_PATH := parser
LEM-IN_PATH := lem-in
UTILS_PATH := utils
BONUS_PATH := bonus

INCLUDE := -I$(HEADER_PATH) 

# LINK

SRC := $(addprefix $(PARSER_PATH)/,$(SRC_PARSER))
SRC += $(addprefix $(LEM-IN_PATH)/,$(SRC_LEM-IN))
SRC += $(addprefix $(UTILS_PATH)/,$(SRC_UTILS))
SRC += $(addprefix $(BONUS_PATH)/,$(SRC_BONUS))

# OBJECTS AND DEPENDENCY

OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)
DEP = $(OBJ:%.o=%.d)

# GLOBAL

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
NAME = lem-in

# UTILS
ECHO= echo -e

# RULES

.PHONY: all
all: 
	@printf "\e[92mCompilation's flags: \e[36m$(CFLAGS)\n"
	@printf "\e[92mGenerating objects :\e[0m\n"
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	@printf "\e[34mGenerated : \e[5;36m$(NAME)\e[0m\n"
	@$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@

-include $(DEP)
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -MMD -c $< -o $@
	@printf "\e[1;31m  >>  \e[4;34m$@\e[0m\n"

.PHONY: clean
clean:
	@printf "\e[1;31mObject's removed\e[0m\n"
	@$(RM) -r $(OBJ_PATH)

.PHONY: fclean
fclean:
	@printf "\e[1;31m$(NAME) removed\e[0m\n"
	@$(MAKE) clean 2> /dev/null
	@$(RM) $(NAME)

.PHONY: re
re:
	@$(MAKE) fclean 2> /dev/null
	@$(MAKE) 

.PHONY: norm
norm: all
	@./scripts/norm src includes

.PHONY: finish
finish:
	@./scripts/norm
	@./scripts/finish
