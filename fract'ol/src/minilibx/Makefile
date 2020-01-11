#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-Ofast

all: $(NOM)

$(NOM):	$(OBJ)
	@ar rcs -r $(NOM) $(OBJ)
	@echo "\033[36m[\033[31;1mMiniLibX\033[0;36m] >> \033[35;4m$(NOM)\033[0;32m ✔\033[0m"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@echo "\033[36m[\033[31;1mMiniLibX\033[0;36m] >> \033[35;4m$(NOM)\033[0;31m ✖\033[0m"
	@rm -f mlx_app
	@echo "\033[36m[\033[31;1mMiniLibX\033[0;36m] >> \033[35;4mmlx_app\033[0;31m ✖\033[0m"

re: clean all
