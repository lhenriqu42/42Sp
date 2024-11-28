# NAME
NAME := fdf
VALGRIND_LOG = valgrind.log

# FLAGS
CFLAGS := -O3 -ffast-math -fno-stack-protector -Wall -Wextra -g3
MLX_FLAGS := -lbsd -lX11 -lXext -lmlx

# LIBS
MLX_PATH := ./libs/minilibx-linux
MLX_NAME := libmlx_Linux.a

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
SRCS := main.c
OBJ := $(addprefix $(BIN_PATH), $(SRCS:%.c=%.o))

all: mlx $(BIN_PATH) print $(NAME)

mlx:
ifeq ($(wildcard $(MLX_PATH)/$(MLX_NAME)),)
	@echo -e "$(CYAN) -------------------------$(COLOR_LIMITER)"
	@echo -e "$(CYAN)| Compiling MINLIBX-LINUX |$(COLOR_LIMITER)"
	@echo -e "$(CYAN)--------------------------$(COLOR_LIMITER)"
	@echo " "
	@make -C $(MLX_PATH) --no-print-directory
endif

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lm -L $(MLX_PATH) $(MLX_FLAGS)
	@echo -e "$(CYAN) --------------------------------------------$(COLOR_LIMITER)"
	@echo -e "$(CYAN)| FDF executable was created successfully!! |$(COLOR_LIMITER)"
	@echo -e "$(CYAN)--------------------------------------------$(COLOR_LIMITER)"
	@echo " "

print: 
	@echo -e "$(CYAN) ----------------------$(COLOR_LIMITER)"
	@echo -e "$(CYAN)| Compiling My Project |$(COLOR_LIMITER)"
	@echo -e "$(CYAN)-----------------------$(COLOR_LIMITER)"
	@echo " "
	
$(BIN_PATH)%.o: %.c
	@echo -e "$(GREEN)[Compiling]$(COLOR_LIMITER) $(notdir $<)..."
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_PATH)
	@echo " "

clean:
	@echo -e "$(RED)[Removing Objects...]$(COLOR_LIMITER)"
	@make clean -C $(MLX_PATH) --no-print-directory
	@rm -rf $(BIN_PATH)

fclean: clean
	@echo -e "$(RED)[Removing $(notdir $(NAME))...]$(COLOR_LIMITER)"
	@rm -rf $(VALGRIND_LOG)
	@rm -rf $(NAME)

re: fclean all

valgrind: all
	@valgrind --leak-check=full \
	--show-leak-kinds=all -s \
	--trace-children=yes \
	--track-origins=yes \
	--log-file=$(VALGRIND_LOG) \
	./$(NAME) ./maps/42.fdf
	@cat $(VALGRIND_LOG)

.PHONY: all clean fclean re mlx print valgrind nf
