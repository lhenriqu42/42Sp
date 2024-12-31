# NAME
NAME := pipex

# FLAGS
CFLAGS := -O3 -fno-stack-protector -Wall -Wextra -g3 -Werror

# LIBS
LIB_PATH := ./libs/libft
LIB_NAME := libft.a

# PATHS
SRC_PATH := ./src/
BIN_PATH := ./bin/
HEADER_PATH := ./includes/

# COLORS
GREEN := \033[32m
RED := \033[31m
CYAN := \033[36m
VIOLET := \033[38;5;208m
COLOR_LIMITER := \033[0m

# SOURCES AND OBJECTS
FILES := main.c exec.c path.c cleaner.c
SRCS := $(addprefix $(SRC_PATH), $(FILES))
OBJ := $(addprefix $(BIN_PATH), $(FILES:%.c=%.o))

all: libft $(BIN_PATH) print $(NAME)

libft:
ifeq ($(wildcard $(LIB_PATH)/$(LIB_NAME)),)
	@make -C $(LIB_PATH) --no-print-directory
	@make get_next_line -C $(LIB_PATH) --no-print-directory
	@make ft_printf -C $(LIB_PATH) --no-print-directory
	@make ft_printf_fd -C $(LIB_PATH) --no-print-directory
endif

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIB_PATH) -lft -I$(HEADER_PATH)
	@printf "$(CYAN) --------------------------------------------$(COLOR_LIMITER)"
	@printf "$(CYAN)| PIPEX executable was created successfully!! |$(COLOR_LIMITER)"
	@printf "$(CYAN)--------------------------------------------$(COLOR_LIMITER)"
	@echo " "

print: 
ifeq ($(wildcard $(NAME)),)
	@printf "$(GREEN) ------------------------$(COLOR_LIMITER)"
	@printf "$(GREEN)| Compiling Main Project |$(COLOR_LIMITER)"
	@printf "$(GREEN)------------------------$(COLOR_LIMITER)"
	@echo " "
endif

$(BIN_PATH)%.o: $(SRC_PATH)%.c
	@printf "$(GREEN)[Compiling]$(COLOR_LIMITER) $(notdir $<)..."
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_PATH)
	@echo " "

clean:
	@printf "$(RED)[Removing Objects...]$(COLOR_LIMITER)\n"
	@make clean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(BIN_PATH)

fclean: clean
	@printf "$(RED)[Removing $(notdir $(NAME))...]$(COLOR_LIMITER)\n"
	@make fclean -C $(LIB_PATH) --no-print-directory
	@rm -rf $(NAME)

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re print libft
