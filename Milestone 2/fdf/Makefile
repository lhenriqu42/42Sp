# NAME
NAME := fdf
VALGRIND_LOG = valgrind.log

# FLAGS
CFLAGS := -O3 -ffast-math -fno-stack-protector -Wall -Wextra -g3
MLX_FLAGS := -lbsd -lX11 -lXext -lmlx

# LIBS
MLX_PATH := ./libs/minilibx-linux
MLX_NAME := libmlx_Linux.a
LIB_PATH := ./libs/libft
LIB_NAME := libft.a

# PATHS
BIN_PATH := ./bin/
HEADER_PATH := ./

# COLORS
GREEN := \033[32m
RED := \033[31m
CYAN := \033[36m
VIOLET := \033[38;5;208m
COLOR_LIMITER := \033[0m

# SOURCES AND OBJECTS
SRCS := main.c error.c
OBJ := $(addprefix $(BIN_PATH), $(SRCS:%.c=%.o))

all: mlx libft $(BIN_PATH) print $(NAME)

libft:
ifeq ($(wildcard $(LIB_PATH)/$(LIB_NAME)),)
	@make -C $(LIB_PATH) --no-print-directory
	@make get_next_line -C $(LIB_PATH) --no-print-directory
	@make ft_printf -C $(LIB_PATH) --no-print-directory
endif

mlx:
ifeq ($(wildcard $(MLX_PATH)/$(MLX_NAME)),)
	@printf "$(CYAN) -------------------------$(COLOR_LIMITER)"
	@printf "$(CYAN)| Compiling MINLIBX-LINUX |$(COLOR_LIMITER)"
	@printf "$(CYAN)--------------------------$(COLOR_LIMITER)"
	@echo " "
	@make -C $(MLX_PATH) --no-print-directory
endif

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lm -L $(LIB_PATH) -lft -L $(MLX_PATH) $(MLX_FLAGS)
	@printf "$(CYAN) --------------------------------------------$(COLOR_LIMITER)"
	@printf "$(CYAN)| FDF executable was created successfully!! |$(COLOR_LIMITER)"
	@printf "$(CYAN)--------------------------------------------$(COLOR_LIMITER)"
	@echo " "

print: 
	@printf "$(CYAN) ----------------------$(COLOR_LIMITER)"
	@printf "$(CYAN)| Compiling My Project |$(COLOR_LIMITER)"
	@printf "$(CYAN)-----------------------$(COLOR_LIMITER)"
	@echo " "
	
$(BIN_PATH)%.o: %.c
	@printf "$(GREEN)[Compiling]$(COLOR_LIMITER) $(notdir $<)..."
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_PATH)
	@echo " "

clean:
	@printf "$(RED)[Removing Objects...]$(COLOR_LIMITER)"
	@make clean -C $(MLX_PATH) --no-print-directory
	@make clean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(BIN_PATH)

fclean: clean
	@printf "$(RED)[Removing $(notdir $(NAME))...]$(COLOR_LIMITER)\n"
	@make fclean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(VALGRIND_LOG)
	@rm -rf $(NAME)

re: fclean
	@make --no-print-directory

valgrind: all
	@valgrind --leak-check=full \
	--show-leak-kinds=all -s \
	--trace-children=yes \
	--track-origins=yes \
	--log-file=$(VALGRIND_LOG) \
	./$(NAME) ./maps/42.fdf
	@cat $(VALGRIND_LOG)

.PHONY: all clean fclean re mlx print valgrind nf libft
