# Nom de l'exécutable du test
NAME = test_checker

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Répertoires
LIBFT_DIR = ./include/libft
MLX_DIR = ./include/minilibx-linux
UTILS_DIR = ./utils
TEST_DIR = ./testeur_file
CHECK_DIR = $(UTILS_DIR)/check_and_init_arg

# Fichiers sources
SRCS = $(TEST_DIR)/test_checker.c \
       $(CHECK_DIR)/check_is_valid.c \
       $(CHECK_DIR)/check_is_cub_file.c \
       $(CHECK_DIR)/check_is_xpm_file.c \
       $(CHECK_DIR)/check_open.c \
       $(UTILS_DIR)/error_msg/print_error.c

OBJS = $(SRCS:.c=.o)

# Inclusion des headers
INCLUDES = -I ./include -I $(UTILS_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)

# Bibliothèques
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Règle principale
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -o $(NAME)

# Compilation des fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation de Libft et MiniLibX si nécessaire
$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

# Nettoyage complet
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Recompile tout proprement
re: fclean all

# Évite que "clean", "fclean" et "re" soient interprétés comme des fichiers
.PHONY: all clean fclean re
