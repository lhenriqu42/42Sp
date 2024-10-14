/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:29:50 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/10/14 11:01:26 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	size_t	count;

	if (c == '\0')
		return (1);
	count = 0;
	if (*str == '\0')
		return (count);
	while (*str)
	{
		count++;
		while (*str != c && *str)
			str++;
		while (*str == c && *str)
			str++;
	}
	return (count);
}

static void	*ft_free_matrix(char **matrix, size_t m_word)
{
	size_t	i;

	i = 0;
	while (i < m_word)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

static char	**fill_matrix(char **matrix, const char *str, char c)
{
	size_t	len;
	size_t	m_word;

	m_word = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		len = 0;
		while (str[len] != c && str[len])
			len++;
		matrix[m_word] = (char *)malloc((len + 1) * sizeof(char));
		if (matrix[m_word] == NULL)
			return (ft_free_matrix(matrix, m_word));
		ft_strlcpy(matrix[m_word], str, len + 1);
		str += len;
		m_word++;
	}
	return (matrix);
}

char	**ft_split(char const *str, char c)
{
	char	**matrix;
	int		count_words;

	while (*str && *str == c)
		str++;
	count_words = ft_count_words(str, c);
	matrix = (char **)malloc((count_words + 1) * sizeof(char *));
	if (matrix == NULL)
		return (NULL);
	matrix = fill_matrix(matrix, str, c);
	matrix[count_words] = NULL;
	return (matrix);
}
