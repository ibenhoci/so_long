NAME = so_long
NAME_B = so_long_bonus

OBJ_DIR = objects/
SRC_DIR = src/

SRC = main.c \
		get_next_line.c \
		init.c \
		utils.c \
		display.c \
		display_utils.c

SRC_B = main.c \
		get_next_line.c \
		init_bonus.c \
		utils.c \
		display_bonus.c \
		display_utils_bonus.c 

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJS_B = $(addprefix $(OBJ_DIR), $(OBJ_B))

HEADER = -I ./include -I ../LeakSanitizer

LIBFT = ./libs/libft/libft.a
LIBMLX42 = "./libs/MLX42/build/libmlx42.a"
FRAMEWORK = -framework Cocoa -framework OpenGL -framework IOKit

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	cc -c $< -o $@ $(HEADER) $(FLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	cd libs/libft && make re
	cd libs && git clone https://github.com/codam-coding-college/MLX42.git
	cd libs/MLX42 && cmake -B build && cmake --build build -j4

$(NAME): $(OBJS)
	rm -rf $(NAME_B)
	cc $(LIBMLX42) $(LIBFT) $(FRAMEWORK) $(OBJS) -lglfw -o $(NAME)

bonus: $(OBJ_DIR) $(NAME_B)

$(NAME_B): $(OBJS_B)
	rm -rf $(NAME)
	cc $(LIBMLX42) $(LIBFT) $(FRAMEWORK) $(OBJS_B) -lglfw -o $(NAME_B)

install_brew:
	echo installing brew
	$HOME/goinfre/.brew && echo 'export PATH=$HOME/goinfre/.brew/bin:$PATH' >> $HOME./zshrc && source $HOME/.zshrc && brew update

install_glfw:
	echo installing glfw
	brew install glfw

install: install_brew install_glfw

clean:
	cd libs/libft && make clean
	rm -rf $(OBJ_DIR)
	rm -rf libs/MLX42

fclean:
	cd libs/libft && make fclean
	rm -rf libs/MLX42
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re: fclean all

.PHONY: all clean fclean re install_glfw install_brew install bonus
