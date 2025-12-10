# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/30 21:50:19 by ohaker            #+#    #+#              #
#    Updated: 2025/12/10 21:53:05 by ohaker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CFLAGS = -Wall -Wextra -Werror -O3 -Iincludes -I/usr/include -Iminilibx-linux -g
SRC = $(addprefix srcs/, \
	extract_map/check_map_even_more.c \
	extract_map/check_map_utils_more.c \
	extract_map/check_map_utils.c \
	extract_map/check_map.c \
	input_handler.c \
	main.c \
	utils.c)

OBJ = $(SRC:.c=.o)
LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = includes/minilibx-linux

# Color definitions for terminal output
NONE		= \033[0m
GREEN		= \033[32;01m
RED			= \033[31;01m
ORANGE		= \033[33;01m

.SILENT:

all:	$(NAME)

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	echo "$(ORANGE)		- Compiling $(NAME)...$(NONE)"
	make -C $(LIBFT_DIR) --silent
	make -C $(MLX_DIR) --silent
	cc $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) $(OBJ) $(LIBFT) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)
	echo "$(GREEN)		- $(NAME) Compiled -$(NONE)"

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	@$(MAKE) clean --no-print-directory -C $(MLX_DIR)
	@$(MAKE) clean --no-print-directory -C $(LIBFT_DIR)
	echo "$(ORANGE)		- Deleted object files$(NONE)"

fclean: clean
	rm -f $(NAME)
	@$(MAKE) clean --no-print-directory -C $(MLX_DIR)
	@$(MAKE) fclean --no-print-directory -C $(LIBFT_DIR)
	echo "$(ORANGE)		- Deleted $(NAME)$(NONE)"

re: fclean all

gitpush:
	git add .; \
	git status; \
	echo "$(ORANGE)		- Enter commit message:$(NONE)"; \
	read input; \
	if [ -z "$$input" ]; then \
		echo "$(RED)		- No commit message entered. Exiting.$(NONE)"; \
	else \
		current_branch=$$(git rev-parse --abbrev-ref HEAD); \
		TIMESTAMP=$$(date '+%Y-%m-%d %H:%M'); \
		git commit -m "$$input" -m "Commit date: $$TIMESTAMP"; \
		git push origin $$current_branch; \
		echo "$(GREEN)		- Pushed to branch '$$current_branch'$(NONE)"; \
	fi

.PHONY: all clean fclean re mygit format