/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:12:52 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/11/29 12:52:30 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src[i] && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char *get_nl_address(const char *s)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char *ft_strdup(const char *s)
{
	size_t i;
	size_t len;
	char *new_string;

	len = 0;
	while (s[len])
		len++;
	new_string = malloc(len + 1);
	i = 0;
	if (new_string == NULL)
		return (NULL);
	while (s[i])
	{
		new_string[i] = s[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
static size_t my_strlen(char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return len;
}
char *ft_strjoin_with_free(char *s1, char *s2)
{
	char *new_string;
	int j;
	int i;

	if (s1 == NULL)
		s1 = ft_strdup("");
	new_string = malloc((my_strlen(s1) + my_strlen(s2) + 1));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new_string[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_string[j++] = s2[i++];
	new_string[j] = '\0';
	free((char *)s1);
	return (new_string);
}
