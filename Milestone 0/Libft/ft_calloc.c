/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:47:30 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/10/12 13:52:10 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    void *allocd_mem;

    allocd_mem = (void *)malloc(count * size);
    if (allocd_mem == NULL)
        return (NULL);
    ft_bzero(allocd_mem, count * size);
    return (allocd_mem);
}