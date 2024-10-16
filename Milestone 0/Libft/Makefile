# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 19:52:41 by lhenriqu          #+#    #+#              #
#    Updated: 2024/10/15 23:31:00 by lhenriqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRCS := ft_atoi.c \
	ft_itoa.c \
	ft_bzero.c \
	ft_split.c \
	ft_calloc.c \
	ft_memcmp.c \
	ft_memchr.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_memcpy.c \
	ft_substr.c \
	ft_striteri.c \
	ft_strlen.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memmove.c \
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
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putchar_fd.c
OBJ = $(SRCS:%.c=%.o)

SRCS_B := ft_lstadd_back_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstmap_bonus.c
OBJ_B = $(SRCS_B:%.c=%.o)

#SRCS_B := ft_lst_remove_node.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_lstmap.c

HEADER := libft.h
CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(OBJ_B)
	@echo "Linking bonus"
	@ar rcs $(NAME) $?
	@ranlib $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $(NAME)"
	@ar rcs $@ $?
	@ranlib $(NAME)


%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_B)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
