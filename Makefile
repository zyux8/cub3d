# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/30 21:50:19 by ohaker            #+#    #+#              #
#    Updated: 2025/11/30 22:29:15 by ohaker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CFLAGS = -Wall -Wextra -Werror -O3 -Iincludes -I/usr/include -Iminilibx-linux -g
SRC = $(addprefix srcs/, \
	main.c)

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

$(NAME): $(OBJ)
	@echo "$(ORANGE)		- Compiling $(NAME)...$(NONE)"
	@make -C $(LIBFT_DIR) --silent
	@make -C $(MLX_DIR) --silent
	@cc $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) $(OBJ) $(LIBFT) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)
	@echo "$(GREEN)		- $(NAME) Compiled -$(NONE)"

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ)
	@echo "$(ORANGE)		- Deleted object files$(NONE)"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(ORANGE)		- Deleted $(NAME)$(NONE)"

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