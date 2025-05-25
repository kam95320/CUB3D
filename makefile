# # Programme
# NAME			=	cub3D

# # Compiler
# CC				=	cc
# CFLAGS			=	-g3 -Wall -Werror -Wextra -g3 -o3
# LDFLAGS			=	-L $(LIBFT_PATH) -lft
# MLXFLAGS		=	-lX11 -lXext -L $(MLX_PATH) -lmlx -lm -lbsd

# # Libft
# LIBFT_PATH		=	./include/libft/
# LIBFT_NAME		=	libft.a
# LIBFT			=	$(LIBFT_PATH)$(LIBFT_NAME)

# # Minilibx
# MLX_PATH		=	./include/minilibx-linux/
# MLX_NAME		=	libmlx.a
# MLX				=	$(MLX_PATH)$(MLX_NAME)

# HEAD			=	-I ./includes/ \
# 					-I $(LIBFT_PATH) \
# 					-I $(MLX_PATH)

# # Sources
# SRCS_NAMES		=	utils/check_and_init_arg/check_arg_init_mlx.c\
# 					utils/initialization/data_initializ.c\
# 					utils/initialization/mlx_initializ.c\
# 					utils/initialization/player_data_initialization.c\
# 					utils/initialization/texture_data_initialization.c\
# 					utils/error_msg/print_error.c\
# 					utils/check_and_init_arg/check_is_valid.c\
# 					utils/check_and_init_arg/check_open.c\
# 					utils/check_and_init_arg/check_is_cub_file.c\
# 					utils/check_and_init_arg/check_is_xpm_file.c\
# 					utils/map_fclt/map_is_valid.c\
# 					utils/map_fclt/take_mem_map.c\
# 					utils/map_fclt/completed_2d.c\
# 					utils/map_fclt/nb_line.c\
# 					utils/map_fclt/manage_space.c\
# 					utils/map_fclt/is_good_print.c\
# 					utils/map_fclt/color.c\
# 					utils/map_fclt/hx_txt.c\
# 					utils/map_fclt/vrb_txt_valid.c\
# 					utils/map_fclt/floor_or_ceiling.c\
# 					utils/map_fclt/all_free.c\
# 					utils/map_fclt/init_var_pl_e_w.c\
# 					utils/map_fclt/init_var_pl_n_s.c\
# 					utils/mlx_initializaton/initialize_mlx.c\
# 					utils/mlx_initializaton/init_img_textures.c\
# 					utils/mlx_initializaton/texture_convert.c\
# 					utils/mlx_initializaton/initialzation_txt.c\
# 					utils/mlx_initializaton/mlx_exit.c\
# 					utils/map_fclt/get_map_size.c\
# 					utils/initialization/initialization_texture.c\
# 					utils/map_world/map_create.c\
# 					utils/map_world/draw_map.c\
# 					utils/init_variables/init_all_var.c\
# 					utils/init_variables/init_all_var_2.c\
# 					utils/utils.c\
# 					all_debug_files/parse_debug.c\
# 					all_debug_files/raycast_debug.c\
# 					all_debug_files/player_debug.c\
# 					utils/main.c


# SRCS			=	$(SRCS_NAMES)
# OBJS			=	$(SRCS:.c=.o)

# # Règles
# all: $(NAME)

# $(NAME): $(OBJS)
# 	@echo "Building Libft..."
# 	@make -sC $(LIBFT_PATH)
# 	@echo "Building MiniLibX..."
# 	@make -sC $(MLX_PATH)
# 	@echo "Linking $(NAME)..."
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) $(LDFLAGS) $(MLXFLAGS)
# 	@echo "\033[1m		______     __  __     ______     _____    \n\
# 		       /\  ___\   /\ \/\ \   /\  == \   /\  __-.  \n\
# 		       \ \ \____  \ \ \_\ \  \ \  __<   \ \ \/\ \ \n\
# 			\ \_____\  \ \_____\  \ \_____\  \ \____- \n\
# 			 \/_____/   \/_____/   \/_____/   \/____/ \n\n\033[0m"

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

# clean:
# 	@echo "Cleaning object files..."
# 	rm -f $(OBJS)
# 	@make clean -C $(LIBFT_PATH)

# fclean: clean
# 	@echo "Removing binary..."
# 	rm -f $(NAME)
# 	@make fclean -C $(LIBFT_PATH)

# re: fclean all

# .PHONY: all clean fclean re


# Programme
# NAME			= cub3D

# # Couleurs ANSI
# PURPLE = \033[38;5;135m
# YELLOW = \033[33m
# CYAN   = \033[36m
# GREEN  = \033[32m
# RED    = \033[31m
# RESET  = \033[0m
# # Compiler
# CC			= cc
# CFLAGS			= -g3 -Wall -Werror -Wextra -g3 -o3
# LDFLAGS			= -L $(LIBFT_PATH) -lft
# MLXFLAGS		= -lX11 -lXext -L $(MLX_PATH) -lmlx -lm -lbsd

# # Libft
# LIBFT_PATH		= ./include/libft/
# LIBFT_NAME		= libft.a
# LIBFT			= $(LIBFT_PATH)$(LIBFT_NAME)

# # Minilibx
# MLX_PATH		= ./include/minilibx-linux/
# MLX_NAME		= libmlx.a
# MLX			= $(MLX_PATH)$(MLX_NAME)

# HEAD			= -I ./includes/ \
# 				-I $(LIBFT_PATH) \
# 				-I $(MLX_PATH)

# # Sources
# SRCS_NAMES		= utils/check_and_init_arg/check_arg_init_mlx.c\
# 				utils/initialization/data_initializ.c\
# 				utils/initialization/mlx_initializ.c\
# 				utils/initialization/player_data_initialization.c\
# 				utils/initialization/texture_data_initialization.c\
# 				utils/error_msg/print_error.c\
# 				utils/check_and_init_arg/check_is_valid.c\
# 				utils/check_and_init_arg/check_open.c\
# 				utils/check_and_init_arg/check_is_cub_file.c\
# 				utils/check_and_init_arg/check_is_xpm_file.c\
# 				utils/map_fclt/map_is_valid.c\
# 				utils/map_fclt/take_mem_map.c\
# 				utils/map_fclt/completed_2d.c\
# 				utils/map_fclt/nb_line.c\
# 				utils/map_fclt/manage_space.c\
# 				utils/map_fclt/is_good_print.c\
# 				utils/map_fclt/color.c\
# 				utils/map_fclt/hx_txt.c\
# 				utils/map_fclt/vrb_txt_valid.c\
# 				utils/map_fclt/floor_or_ceiling.c\
# 				utils/map_fclt/all_free.c\
# 				utils/map_fclt/init_var_pl_e_w.c\
# 				utils/map_fclt/init_var_pl_n_s.c\
# 				utils/mlx_initializaton/initialize_mlx.c\
# 				utils/mlx_initializaton/init_img_textures.c\
# 				utils/mlx_initializaton/texture_convert.c\
# 				utils/mlx_initializaton/initialzation_txt.c\
# 				utils/mlx_initializaton/mlx_exit.c\
# 				utils/map_fclt/get_map_size.c\
# 				utils/initialization/initialization_texture.c\
# 				utils/map_world/map_create.c\
# 				utils/map_world/draw_map.c\
# 				utils/init_variables/init_all_var.c\
# 				utils/init_variables/init_all_var_2.c\
# 				utils/utils.c\
# 				all_debug_files/parse_debug.c\
# 				all_debug_files/raycast_debug.c\
# 				all_debug_files/player_debug.c\
# 				utils/main.c

# SRCS			= $(SRCS_NAMES)
# OBJS			= $(SRCS:.c=.o)

# # Règles
# all: $(NAME)

# $(NAME): $(OBJS)

# 	@echo "\033[38;5;135mBuilding Libft...\033[0m"
# 	@make -sC $(LIBFT_PATH)
# 	@echo "\033[38;5;135mBuilding MiniLibX...\033[0m"
# 	@make -sC $(MLX_PATH)
# 	@echo "\033[38;5;135mLinking $(NAME)...\033[0m"
# 	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) $(LDFLAGS) $(MLXFLAGS)
# 	@echo "$(PURPLE)"
# 	@echo "\033[1m\t\t______     __  __     ______     _____    \n\
# \t       /\  ___\   /\ \\/\ \   /\  == \   /\  __-.  \n\
# \t       \ \ \____  \ \ \_\ \  \ \  __<   \ \ \\/\ \ \n\
# \t        \ \_____\  \ \_____\  \ \_____\  \ \____- \n\
# \t         \/_____/   \/_____/   \/_____/   \/____/ \n\n\033[0m"
# 	@echo "$(RESET)"
# 	@echo "\n\033[38;5;135m🕹️ COMMANDES CUB3D\033[0m"
# 	@echo "\033[32m   W     \033[0m→ Avancer"
# 	@echo "\033[32m   S     \033[0m→ Reculer"
# 	@echo "\033[32m   A     \033[0m→ Aller à gauche"
# 	@echo "\033[32m   D     \033[0m→ Aller à droite"
# 	@echo "\033[33m← / → \033[0m→ Tourner la caméra"
# 	@echo "\033[31m  ESC   \033[0m→ Quitter le jeu"
# 	@echo "\n\033[38;5;135m🎯 RÈGLES CUB3D\033[0m"
# 	@echo "\033[36m - Une seule position de joueur (N, S, E ou W dans .cub)\033[0m"
# 	@echo "\033[36m - Le joueur regarde vers : direction définie dans la map .cub\033[0m"
# 	@echo "\033[36m - La carte doit être bien fermée (1 tout autour)\033[0m"
# 	@echo "\033[36m - Fichier .cub doit contenir les textures et couleurs valides\033[0m"
# 	@echo "\033[36m - Les touches fléchées ← / → tournent la vue\033[0m"

# %.o: %.c
# 	@$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

# clean:
# 	@echo "Cleaning object files..."
# 	@rm -f $(OBJS)
# 	@make clean -C $(LIBFT_PATH)

# fclean: clean
# 	@echo "Removing binary..."
# 	@rm -f $(NAME)
# 	@make fclean -C $(LIBFT_PATH)

# re: fclean all

# .PHONY: all clean fclean re



# Programme
NAME			= cub3D

# Compiler
CC			= cc
CFLAGS			= -g3 -Wall -Werror -Wextra -g3 -o3
LDFLAGS			= -L $(LIBFT_PATH) -lft
MLXFLAGS		= -lX11 -lXext -L $(MLX_PATH) -lmlx -lm -lbsd

# Libft
LIBFT_PATH		= ./include/libft/
LIBFT_NAME		= libft.a
LIBFT			= $(LIBFT_PATH)$(LIBFT_NAME)

# Minilibx
MLX_PATH		= ./include/minilibx-linux/
MLX_NAME		= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

HEAD			= -I ./includes/ \
				-I $(LIBFT_PATH) \
				-I $(MLX_PATH)

# Sources
SRCS_NAMES		= utils/check_and_init_arg/check_arg_init_mlx.c\
				utils/initialization/data_initializ.c\
				utils/initialization/mlx_initializ.c\
				utils/initialization/player_data_initialization.c\
				utils/error_msg/print_error.c\
				utils/check_and_init_arg/check_is_valid.c\
				utils/check_and_init_arg/check_open.c\
				utils/check_and_init_arg/check_is_cub_file.c\
				utils/check_and_init_arg/check_is_xpm_file.c\
				utils/map_fclt/textures.c\
				utils/map_fclt/check_close_map.c\
				utils/map_fclt/map_is_valid.c\
				utils/map_fclt/take_mem_map.c\
				utils/map_fclt/completed_2d.c\
				utils/map_fclt/nb_line.c\
				utils/map_fclt/manage_space.c\
				utils/map_fclt/is_good_print.c\
				utils/map_fclt/ceil_floor.c\
				utils/map_fclt/tstrcmp.c\
				utils/map_fclt/color.c\
				utils/map_fclt/hx_txt.c\
				utils/map_fclt/vrb_txt_valid.c\
				utils/map_fclt/floor_or_ceiling.c\
				utils/map_fclt/all_free.c\
				utils/map_fclt/init_var_pl_e_w.c\
				utils/map_fclt/init_var_pl_n_s.c\
				utils/mlx_initializaton/initialize_mlx.c\
				utils/mlx_initializaton/mlx_exit.c\
				utils/map_fclt/get_map_size.c\
				utils/map_fclt/rgb_nb_convert.c\
				utils/init_variables/init_all_var.c\
				utils/init_variables/init_all_var_2.c\
				utils/utils.c\
				utils/utils_2.c\
				utils/raycating/ray_utils_1.c\
				utils/raycating/ray_utils_2.c\
				utils/player/init_player.c\
				utils/player/key_screen.c\
				utils/player/move_player.c\
				utils/player/rotate_player.c\
				utils/player/init_direct_player.c\
				all_debug_files/parse_debug.c\
				all_debug_files/raycast_debug.c\
				all_debug_files/player_debug.c\
				utils/raycating/cast_single_ray.c\
				utils/raycating/draw_vertical_line.c\
				utils/raycating/ray_loop.c\
				utils/raycating/raycast.c\
				all_debug_files/raycast_calc_debug.c\
				utils/main.c

SRCS			= $(SRCS_NAMES)
OBJS			= $(SRCS:.c=.o)

# Règles
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[38;5;135mBuilding Libft...\033[0m"
	@make -sC $(LIBFT_PATH)
	@echo "\033[38;5;135mBuilding MiniLibX...\033[0m"
	@make -sC $(MLX_PATH)
	@echo "\033[38;5;135mLinking $(NAME)...\033[0m"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) $(LDFLAGS) $(MLXFLAGS)
	@echo "\033[38;5;135m"
	@echo "\033[1m\t\t______     __  __     ______     _____    \n\
\t       /\  ___\   /\ \\/\ \   /\  == \   /\  __-.  \n\
\t       \ \ \____  \ \ \_\ \  \ \  __<   \ \ \\/\ \ \n\
\t        \ \_____\  \ \_____\  \ \_____\  \ \____- \n\
\t         \/_____/   \/_____/   \/_____/   \/____/ \n\n\033[0m"
	@echo "$(RESET)"
	@echo "\n\033[38;5;135m🕹️ COMMANDES CUB3D\033[0m"
	@echo "\033[32m   W     \033[0m→ Avancer"
	@echo "\033[32m   S     \033[0m→ Reculer"
	@echo "\033[32m   A     \033[0m→ Aller à gauche"
	@echo "\033[32m   D     \033[0m→ Aller à droite"
	@echo "\033[33m← / → \033[0m→ Tourner la caméra"
	@echo "\033[31m  ESC   \033[0m→ Quitter le jeu"
	@echo "\n\033[38;5;135m🎯 RÈGLES CUB3D\033[0m"
	@echo "\033[36m - Une seule position de joueur (N, S, E ou W dans .cub)\033[0m"
	@echo "\033[36m - Le joueur regarde vers : direction définie dans la map .cub\033[0m"
	@echo "\033[36m - La carte doit être bien fermée (1 tout autour)\033[0m"
	@echo "\033[36m - Fichier .cub doit contenir les textures et couleurs valides\033[0m"
	@echo "\033[36m - Les touches fléchées ← / → tournent la vue\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

clean:
	@rm -f $(OBJS)
	@make clean -sC $(LIBFT_PATH)
	@echo "\33[36m✨ Everything is clean.\033[0m"
	

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC $(LIBFT_PATH)
	@echo "\33[38;5;135m🔥 Full clean complete: binary removed.\033[0m"

re: fclean all

.PHONY: all clean fclean re