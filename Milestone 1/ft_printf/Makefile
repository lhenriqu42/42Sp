NAME := libftprintf.a
CFLAGS := -Wall -Wextra -Werror

# PATHS
BIN_PATH := ./bin/
HEADERS_PATH := ./headers/
SOURCES_PATH := ./src/

# COLORS
GREEN = "\033[32m"
RED = "\033[31m"
VIOLET = "\033[38;5;208m"
COLOR_LIMITER = "\033[0m"

# SOURCES
SRCS = ft_printf.c \
		strings.c \
		numbers.c
$(addprefix $(BIN_PATH), $(SOURCES:%.c=%.o))
OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJECTS)
	@echo $(VIOLET) -------------------------------------------- $(COLOR_LIMITER)
	@echo $(VIOLET)"| libftprintf.a Was Generated Successfully!! |"$(COLOR_LIMITER)
	@echo $(VIOLET) -------------------------------------------- $(COLOR_LIMITER)
	@echo " "
	@ar rcs $(NAME) $?