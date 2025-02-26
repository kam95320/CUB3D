# Programme
NAME			=	cub3D

# Compiler
CC				=	gcc
CFLAGS			=	-g3 -Wall -Werror -Wextra
LDFLAGS			=	-L $(LIBFT_PATH) -lft
MLXFLAGS		=	-lX11 -lXext -L $(MLX_PATH) -lmlx -lm -lbsd

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
SRCS_NAMES		=	utils/check_and_init_arg/check_arg_init_mlx.c\
					utils/initialization/data_initializ.c\
					utils/initialization/mlx_initializ.c\
					utils/initialization/player_data_initialization.c\
					utils/initialization/texture_data_initialization.c\
					utils/error_msg/print_error.c\
					utils/check_and_init_arg/check_is_valid.c\
					utils/check_and_init_arg/check_open.c\
					utils/check_and_init_arg/check_is_cub_file.c\
					utils/check_and_init_arg/check_is_xpm_file.c\
					utils/map_fclt/map_is_valid.c\
					utils/map_fclt/take_mem_map.c\
					utils/map_fclt/completed_2d.c\
					utils/map_fclt/nb_line.c\
					utils/map_fclt/manage_space.c\
					utils/map_fclt/is_good_print.c\
					utils/map_fclt/color.c\
					utils/map_fclt/hx_txt.c\
					utils/map_fclt/vrb_txt_valid.c\
					utils/map_fclt/floor_or_ceiling.c\
					utils/map_fclt/all_free.c\
					utils/map_fclt/init_var_pl_e_w.c\
					utils/map_fclt/init_var_pl_n_s.c\
					utils/mlx_initializaton/initialize_mlx.c\
					utils/mlx_initializaton/init_img_textures.c\
					utils/mlx_initializaton/texture_convert.c\
					utils/mlx_initializaton/initialzation_txt.c\
					utils/mlx_initializaton/mlx_exit.c\
					utils/raycast/racasting.c\
					utils/raycast/affmap.c\
					utils/raycast/setblock.c\
					utils/raycast/setpixel.c\
					utils/main.c


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
