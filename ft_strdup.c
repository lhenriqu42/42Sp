/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:57:18 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/10/11 14:59:03 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	ptr = malloc(len * sizeof(char *));
	while (i < len)
		ptr[i++] = s[i];
	return (ptr);
}
