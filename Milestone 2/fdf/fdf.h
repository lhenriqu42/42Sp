/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:33:20 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/11/29 14:41:57 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libs/minilibx-linux/mlx.h"
# include "./libs/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

// WINDOW CONFIG
# define W_WIDTH 1300
# define W_HEIGHT 900
# define W_NAME "FDF"

// BOOLEAN
# define TRUE  1
# define FALSE 0

// ERRORS
# define E_NO_ERROR 0
# define E_INVALID_MAP 1
# define E_ALLOCATE_FDF 2
# define E_ALLOCATE_MLX 3
# define E_ALLOCATE_MAP 4
# define E_ALLOCATE_WINDOW 5
# define E_ALLOCATE_MATRIX 6
# define E_ALLOCATE_CAMERA 7
# define E_BRESENHAM_ERROR 8
# define E_PIXEL_OUTSIDE_WINDOW 9

// COLORS
# define C_SUCCESS "\033[32;3m"
# define C_ERROR "\033[32;3m"
# define C_BREAK "\033[0m"


 
#endif