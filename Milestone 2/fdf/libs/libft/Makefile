# ===========================================================================
# ================================ COLORS ===================================
# ===========================================================================

GREEN = "\033[32;1m"
RED = "\033[31;1m"
CYAN = "\033[36;1;3;208m"
WHITE = "\033[37;1;4m"
COLOR_LIMITER = "\033[0m"

# ===========================================================================
# ================================= LIBFT ===================================
# ===========================================================================

LIB_NAME = Libft
LIB_SOURCES_PATH = ./src/
LIB_HEADER_PATH = ./
LIB_BIN_PATH = ./bin/

LIB_SOURCES = \
	ft_abs.c \
	ft_itoa.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_split.c \
	ft_calloc.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_substr.c \
	ft_strlen.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_striteri.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_atoi_base.c \
	ft_putendl_fd.c \
	ft_putchar_fd.c 

LIB_OBJECTS = $(addprefix $(LIB_BIN_PATH), $(LIB_SOURCES:%.c=%.o))

# ===========================================================================
# ============================ GET NEXT LINE ================================
# ===========================================================================

GNL_NAME = GNL
GNL_SOURCES_PATH = ./get_next_line/src/
GNL_HEADER_PATH = ./get_next_line/includes/
GNL_BIN_PATH = ./get_next_line/bin/

GNL_SOURCES = \
	get_next_line_utils.c \
	get_next_line.c

GNL_OBJECTS = $(addprefix $(GNL_BIN_PATH), $(GNL_SOURCES:%.c=%.o))

# ===========================================================================
# ============================= FT_PRINTF ===================================
# ===========================================================================

PRINTF_NAME = Printf
PRINTF_SOURCES_PATH = ./ft_printf/src/
PRINTF_HEADER_PATH = ./ft_printf/includes/
PRINTF_BIN_PATH = ./ft_printf/bin/

PRINTF_SOURCES = \
	string_functions.c \
	number_functions.c \
	ft_printf.c 

PRINTF_OBJECTS = $(addprefix $(PRINTF_BIN_PATH), $(PRINTF_SOURCES:%.c=%.o))

# ===========================================================================
# ============================= MAIN RULES ==================================
# ===========================================================================

NAME := libft.a
CFLAGS := -Wall -Wextra -Werror

all: $(LIB_BIN_PATH) $(NAME)

$(LIB_BIN_PATH)%.o: $(LIB_SOURCES_PATH)%.c
	@echo -e $(GREEN)[Compiling]$(COLOR_LIMITER) \
	$(WHITE)$(notdir $(<))...$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(LIB_HEADER_PATH)
	@echo -e " "

$(NAME): $(LIB_OBJECTS)
	@echo -e $(CYAN)" ---------------------------------------"$(COLOR_LIMITER)
	@echo -e $(CYAN)"|  $(LIB_NAME)  Was Compiled Successfully!! |"$(COLOR_LIMITER)
	@echo -e $(CYAN)"---------------------------------------"$(COLOR_LIMITER)
	@echo -e " "
	@ar rcs $(NAME) $?

$(LIB_BIN_PATH):
	@mkdir -p $(LIB_BIN_PATH)

get_next_line:
	@make --no-print-directory \
	LIB_NAME="$(GNL_NAME)" \
	LIB_BIN_PATH="$(GNL_BIN_PATH)" \
	LIB_SOURCES_PATH="$(GNL_SOURCES_PATH)" \
	LIB_OBJECTS="$(GNL_OBJECTS)" \
	LIB_HEADER_PATH="$(GNL_HEADER_PATH)"

ft_printf:
	@make --no-print-directory \
	LIB_NAME="$(PRINTF_NAME)" \
	LIB_BIN_PATH="$(PRINTF_BIN_PATH)" \
	LIB_SOURCES_PATH="$(PRINTF_SOURCES_PATH)" \
	LIB_OBJECTS="$(PRINTF_OBJECTS)" \
	LIB_HEADER_PATH="$(PRINTF_HEADER_PATH)"
	
clean:
	@echo -e $(RED)[Removing Objects]$(COLOR_LIMITER)
	@rm -rf $(LIB_BIN_PATH)
	@rm -rf $(GNL_BIN_PATH)
	@rm -rf $(PRINTF_BIN_PATH)

fclean: clean
	@echo -e $(RED)[Removing $(NAME)]$(COLOR_LIMITER)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re get_next_line ft_printf
