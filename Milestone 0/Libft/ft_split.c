/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:29:50 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/10/13 11:38:46 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_countc(char const *str, char c)
{
    int counter;

    counter = 0;
    while(*str == c)
        str++;
    while (*str)
    {
        if (*str == c)
        {
            counter++;
            while (*str != c)
                str++;
        }
        str++;
    }
    return (counter + 1);
}

char **ft_split(char const *str, char c)
{
    int words_count;
    size_t i;
    size_t len;
    char **matrix;

    i = 0;
    len = ft_strlen(str);
    words_count = ft_countc(str, c);
    while (str[i])
    {
    }
}