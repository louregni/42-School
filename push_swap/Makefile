# SOURCES 

SRC_PUSH := push_swap.c sort.c action.c opti.c
SRC_CHECKER := checker.c visualizer.c create_list.c instruction.c \
			   init.c action.c pilot.c
SRC_UTILS := quicksort.c ft_bzero.c ft_diff.c ft_strlen.c
SRC_COM := get_number.c list.c parser.c create_list.c

# PATH

SRC_PATH := src
OBJ_PATH := obj
PUSH_PATH := push_swap
CHECKER_PATH := checker
UTILS_PATH := utils
COMMON_PATH := common
HEADER_PATH := includes
FRAMEWORK_PATH := frameworks
FRAMEWORK := SDL2 SDL2_ttf

INCLUDE := -I$(HEADER_PATH) $(FRAMEWORK:%=-I$(FRAMEWORK_PATH)/%.framework/Headers/)

# LINK

SRC_PUSH := $(addprefix $(PUSH_PATH)/,$(SRC_PUSH))
#SRC_CHECKER := $(addprefix $(CHECKER_PATH)/,$(SRC_CHECKER))
SRC := $(addprefix $(UTILS_PATH)/,$(SRC_UTILS))
SRC += $(addprefix $(COMMON_PATH)/,$(SRC_COM))


# OBJECTS AND DEPENDENCY

OBJ = $(SRC:%.c=$(OBJ_PATH)/%.o)
OBJ_CHECKER = $(SRC_CHECKER:%.c=$(OBJ_PATH)/$(CHECKER_PATH)/%.o)
OBJ_PUSH = $(SRC_PUSH:%.c=$(OBJ_PATH)/%.o)
DEP = $(OBJ:%.o=%.d)
DEP += $(OBJ_CHECKER:%.o=%.d)
DEP += $(OBJ_PUSH:%.o=%.d)

# GLOBAL

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME1 = push_swap
NAME2 = checker
LIB := -rpath @loader_path/$(FRAMEWORK_PATH) $(addprefix -framework ,$(FRAMEWORK)) -F $(FRAMEWORK_PATH) 

# RULES

.PHONY: all
all: 
	@echo "\033[32mCompilation's flags: \033[36m$(CFLAGS)"
	@echo "\033[32mFrameworks : \033[36m$(FRAMEWORK)"
	@echo "\033[32mGenerating objects :\033[0m"
	@$(MAKE) $(NAME1)
	@$(MAKE) $(NAME2)

$(NAME1): $(OBJ) $(OBJ_PUSH)
	@echo "\033[34mGenerated : \033[5;36m$(NAME1)\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@

$(NAME2): $(OBJ) $(OBJ_CHECKER)
	@echo "\033[34mGenerated : \033[5;36m$(NAME2)\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDE) $(LIB) $^ -o $@

-include $(DEP)
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) -MMD -c $< -o $@
	@echo "\033[1;31m  >>  \033[4;34m$@\033[0m"

$(OBJ_PATH)/$(CHECKER_PATH)/%.o: $(SRC_PATH)/$(CHECKER_PATH)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CXXLAGS) $(INCLUDE) -MMD -c $< -o $@
	@echo "\033[1;31m  >>  \033[4;34m$@\033[0m"

.PHONY: clean
clean:
	@echo "\033[1;31mObject's removed\033[0m"
	@$(RM) -r $(OBJ_PATH)

.PHONY: fclean
fclean:
	@echo "\033[1;31m$(NAME1) & $(NAME2) removed\033[0m"
	@$(MAKE) clean
	@$(RM) $(NAME1)
	@$(RM) $(NAME2)

.PHONY: re
re:
	@$(MAKE) fclean
	@$(MAKE) all
