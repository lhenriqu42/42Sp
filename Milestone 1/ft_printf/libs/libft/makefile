# PATH VARIABLES
HEADERS_PATH = ../../headers/
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
LIBS_PATH = ./libs/

# COMPILATION
CC = cc
FLAGS = -Wall -Wextra -Werror

# BASH COMMANDS
RM = rm -f
MKDIR = mkdir -p

# FILES
LIBNAME = libft.a
SRCS = ft_atoi.c ft_itoa.c ft_bzero.c ft_split.c ft_calloc.c ft_memcmp.c \
       ft_memchr.c ft_memset.c ft_strchr.c ft_strdup.c ft_memcpy.c \
       ft_substr.c ft_striteri.c ft_strlen.c ft_isalnum.c ft_isalpha.c \
       ft_isascii.c ft_isdigit.c ft_isprint.c ft_memmove.c ft_strjoin.c \
       ft_strlcat.c ft_strlcpy.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
       ft_strrchr.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_putnbr_fd.c \
       ft_putstr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_lstadd_back_bonus.c \
       ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
       ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
       ft_lstmap_bonus.c

OBJS = $(SRCS:%.c=%.o)
SRCS := $(addprefix $(SRCS_PATH), $(SRCS))
OBJS := $(addprefix $(OBJS_PATH), $(OBJS))

# TARGETS
all: prep $(LIBNAME)

prep:
	@$(MKDIR) $(OBJS_PATH) $(LIBS_PATH)

$(LIBNAME): $(OBJS)
	@ar -rcs $(LIBS_PATH)$(LIBNAME) $(OBJS)
	@echo "Library $(LIBNAME) created in $(LIBS_PATH)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	@$(CC) $(FLAGS) -c -I $(HEADERS_PATH) $< -o $@
	@echo "Compiled $< into $@"

clean:
	@$(RM) $(OBJS)
	@echo "Object files cleaned"

fclean: clean
	@$(RM) $(LIBS_PATH)$(LIBNAME)
	@echo "Library cleaned"

re: fclean all

.PHONY: all clean fclean re
