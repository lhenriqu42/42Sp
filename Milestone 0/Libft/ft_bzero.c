/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:02:36 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/10/11 15:19:59 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = 0;
}
// int	main(void)
// {
// 	char str[] = "test";
// 	printf("before: %s\n", str);
// 	ft_bzero(str, 2);
// 	printf("after: %s\n", str + 2);
// 	return (0);
// }