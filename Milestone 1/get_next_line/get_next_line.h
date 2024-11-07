/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:30:48 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/11/07 15:47:20 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# define ARRAY_SIZE 2048

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h> //EXCLUIR <-----------------------------------------

typedef struct s_data
{
	int		fd;
	int		nl_index;
	int		str_len;
	char	buffer[BUFFER_SIZE];
	char	string[ARRAY_SIZE];
	struct s_data	*next;
}			t_data;

t_data	*calloc_new_struct(int fd);
t_data	*init_data(t_data **data, int fd);

#endif
