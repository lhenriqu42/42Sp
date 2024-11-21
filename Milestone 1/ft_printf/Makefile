NAME := libftprintf.a
CFLAGS := -Wall -Wextra -Werror

# PATHS
BIN_PATH = ./bin/

# COLORS
GREEN = "\033[32m"
RED = "\033[31m"
VIOLET = "\033[38;5;208m"
COLOR_LIMITER = "\033[0m"

# SOURCES
SRCS = 	\
	ft_printf.c \
	string_functions.c \
	number_functions.c \

OBJS = $(addprefix $(BIN_PATH), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(BIN_PATH) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo $(VIOLET) -------------------------------------------- $(COLOR_LIMITER)
	@echo $(VIOLET)"| libftprintf.a Was Generated Successfully!! |"$(COLOR_LIMITER)
	@echo $(VIOLET) -------------------------------------------- $(COLOR_LIMITER)
	@echo " "

$(BIN_PATH)%.o: %.c
	@echo $(GREEN)[Compiling]$(COLOR_LIMITER) $(notdir $(<))...
	@$(CC) $(CFLAGS) -c $< -o $@ -I .

$(BIN_PATH):
	@echo $(GREEN)[mkdir]$(COLOR_LIMITER) $(BIN_PATH)
	@mkdir -p $(BIN_PATH)

clean:
	@echo $(RED)[Removing Objects...]$(COLOR_LIMITER)
	@rm -rf $(BIN_PATH)

fclean: clean
	@echo $(RED)[Removing $(notdir $(NAME))...]$(COLOR_LIMITER)
	@rm -f $(NAME)

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re
