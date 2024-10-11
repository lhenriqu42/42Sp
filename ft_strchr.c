/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:33:51 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/10/11 14:46:01 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int i)
{
	int	j;

	j = 0;
	while (s[j] && s[j] != i)
		j++;
	return ((char *)&s[j]);
}

// int	main(void)
// {
// 	printf("\nTEST->| %c |\n", *ft_strchr("testando", 'a'));
// }