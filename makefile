# Programme
NAME			=	cub3D

# Compiler
CC				=	gcc
CFLAGS			=	-g3 -Wall -Werror -Wextra
LDFLAGS			=	-L $(LIBFT_PATH) -lft
MLXFLAGS		=	-lX11 -lXext -L $(MLX_PATH) -lmlx -lm

# Libft
LIBFT_PATH		=	./include/libft/
LIBFT_NAME		=	libft.a
LIBFT			=	$(LIBFT_PATH)$(LIBFT_NAME)

# Minilibx
MLX_PATH		=	./include/minilibx-linux/
MLX_NAME		=	libmlx.a
MLX				=	$(MLX_PATH)$(MLX_NAME)

HEAD			=	-I ./includes/ \
					-I $(LIBFT_PATH) \
					-I $(MLX_PATH)

# Sources
SRCS_NAMES		=	utils/essai.c
SRCS			=	$(SRCS_NAMES)
OBJS			=	$(SRCS:.c=.o)

# Règles
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Building Libft..."
	@make -sC $(LIBFT_PATH)
	@echo "Building MiniLibX..."
	@make -sC $(MLX_PATH)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) $(LDFLAGS) $(MLXFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)

fclean: clean
	@echo "Removing binary..."
	rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re