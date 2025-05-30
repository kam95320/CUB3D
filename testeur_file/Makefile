# Nom de l'exécutable du test
NAME = test_checker

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

# Répertoires
ROOT_DIR = ..
LIBFT_DIR = $(ROOT_DIR)/include/libft
MLX_DIR = $(ROOT_DIR)/include/minilibx-linux
UTILS_DIR = $(ROOT_DIR)/utils
TEST_DIR = $(ROOT_DIR)/testeur_file
CHECK_DIR = $(UTILS_DIR)/check_and_init_arg
MAP_DIR =  	$(UTILS_DIR)/map_fclt
ERROR_DIR = $(UTILS_DIR)/error_msg

# Fichiers sources
SRCS = $(TEST_DIR)/test_checker.c \
       $(CHECK_DIR)/check_is_valid.c \
       $(CHECK_DIR)/check_is_cub_file.c \
       $(CHECK_DIR)/check_is_xpm_file.c \
       $(CHECK_DIR)/check_open.c \
 	   $(MAP_DIR)/take_mem_map.c \
	   $(MAP_DIR)/completed_2d.c\
	   $(MAP_DIR)/nb_line.c\
	   $(MAP_DIR)/map_is_valid.c\
	   $(ERROR_DIR)/print_error.c\
	   load_map_from_file.c\
	   $(MAP_DIR)/manage_space.c\
	   $(MAP_DIR)/is_good_print.c\
	   $(MAP_DIR)/all_free.c\
	   $(MAP_DIR)/vrb_txt_valid.c\
	   $(MAP_DIR)/color.c\
	   $(MAP_DIR)/floor_or_ceiling.c\
		$(MAP_DIR)/hx_txt.c

	   


OBJS = $(SRCS:.c=.o)

# Inclusion des headers
INCLUDES = -I $(ROOT_DIR)/include -I $(UTILS_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)

# Bibliothèques
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Règle principale
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -o $(NAME)

# Compilation des fichiers .c en .o
$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(CHECK_DIR)/%.o: $(CHECK_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(ERROR_DIR)/%.o: $(ERROR_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
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
