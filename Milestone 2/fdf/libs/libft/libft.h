/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:26:03 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/10/11 09:26:03 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# include "./ft_printf/includes/ft_printf.h"  // Include for ft_printf functionality
# include "./get_next_line/includes/get_next_line.h"  // Include for get_next_line functionality

// Returns the absolute value of a floating-point number
float	ft_abs(float number);

// Returns 1 if the character is alphanumeric (a-z, A-Z, 0-9)
int		ft_isalnum(int c);

// Returns 1 if the character is an alphabet letter (a-z, A-Z)
int		ft_isalpha(int c);

// Returns 1 if the character is an ASCII character (0-127)
int		ft_isascii(int c);

// Returns 1 if the character is a digit (0-9)
int		ft_isdigit(int c);

// Returns 1 if the character is a printable character (32-126)
int		ft_isprint(int c);

// Returns the lowercase equivalent of a character if it is uppercase
int		ft_tolower(int c);

// Returns the uppercase equivalent of a character if it is lowercase
int		ft_toupper(int c);

// Converts a string to an integer (base 10)
int		ft_atoi(const char *str);

// Converts a string to an integer for a specific base (e.g., hexadecimal, octal)
int		ft_atoi_base(const char *str, int str_base);

// Compares two strings lexicographically (up to 'n' characters)
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// Compares two blocks of memory byte by byte
int		ft_memcmp(const void *m1, const void *m2, size_t n);

// (malloc) Converts an integer to a string representation
char	*ft_itoa(int n);

// (malloc) Duplicates a string (allocates memory and copies the string)
char	*ft_strdup(const char *s);

// Finds the first occurrence of a character in a string
char	*ft_strchr(const char *s, int c);

// Finds the last occurrence of a character in a string
char	*ft_strrchr(const char *s, int c);

// (malloc) Concatenates two strings into a new string
char	*ft_strjoin(char const *s1, char const *s2);

// (malloc) Removes leading and trailing characters from a string
char	*ft_strtrim(char const *s1, char const *set);

// Finds the first occurrence of a substring within a string (up to 'len' characters)
char	*ft_strnstr(const char *s1, const char *s2, size_t len);

// (malloc) Extracts a substring from a string
char	*ft_substr(char const *s, unsigned int start, size_t len);

// (malloc) Applies a function to each character of a string, returning a new string
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// (malloc) Splits a string into an array of strings based on a delimiter
char	**ft_split(char const *s, char c);

// Returns the length of a string (excluding the null-terminator)
size_t	ft_strlen(const char *s);

// Concatenates two strings, ensuring the destination buffer does not overflow
size_t	ft_strlcat(char *dest, const char *src, size_t d_size);

// Copies a string into a buffer, ensuring the destination buffer does not overflow
size_t	ft_strlcpy(char *dest, const char *src, size_t d_size);

// Allocates memory for an array of 'n' elements of size 'size' and initializes them to zero
void	*ft_calloc(size_t n, size_t size);

// Fills a block of memory with a specific byte value
void	*ft_memset(void *b, int c, size_t len);

// Copies a block of memory from src to dest
void	*ft_memcpy(void *dest, const void *src, size_t n);

// Searches a block of memory for a specific byte value
void	*ft_memchr(const void *s, int c, size_t n);

// Moves a block of memory from src to dest (handles overlapping regions)
void	*ft_memmove(void *dest, const void *src, size_t n);

// Sets a block of memory to zero
void	ft_bzero(void *s, size_t n);

// Writes an integer to the specified file descriptor
void	ft_putnbr_fd(int n, int fd);

// Writes a string to the specified file descriptor
void	ft_putstr_fd(char *s, int fd);

// Writes a character to the specified file descriptor
void	ft_putchar_fd(char c, int fd);

// Writes a string followed by a newline to the specified file descriptor
void	ft_putendl_fd(char *s, int fd);

// Applies a function to each character of a string
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

#endif
