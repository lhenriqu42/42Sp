/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhenriqu <lhenriqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:52:07 by lhenriqu          #+#    #+#             */
/*   Updated: 2024/11/29 09:57:34 by lhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void handle_error(short exit_code)
{
    if (exit_code == E_NO_ERROR)
        ft_printf(C_SUCCESS "FDF closed, Thank You :)\n" C_BREAK);
    else if (exit_code == E_INVALID_MAP)
        ft_printf(C_ERROR "Error, invalid map name :(" C_BREAK);
    else if (exit_code == E_ALLOCATE_FDF)
        ft_printf(C_ERROR "Error, unable to allocate fdf :(" C_BREAK);
    else if (exit_code == E_ALLOCATE_MLX)
        ft_printf(C_ERROR "Error, unable to allocate mlx :(" C_BREAK);
    else if (exit_code == E_ALLOCATE_WINDOW)
        ft_printf(C_ERROR "Error, unable to allocate window :(" C_BREAK);
    else if (exit_code == E_PIXEL_OUTSIDE_WINDOW)
        ft_printf(C_ERROR "Error, pixel outside window range :(" C_BREAK);
    else if (exit_code == E_BRESENHAM_ERROR)
        ft_printf(C_ERROR "Error, unable to use bresenham :(" C_BREAK);
    else if (exit_code == E_ALLOCATE_MAP)
        ft_printf(C_ERROR "Error, unable to allocate map :(" C_BREAK);
    else if (exit_code == E_ALLOCATE_MATRIX)
        ft_printf(C_ERROR "Error, unable to allocate matrix :(" C_BREAK);
    else if (exit_code == E_ALLOCATE_CAMERA)
        ft_printf(C_ERROR "Error, unable to allocate camera :(" C_BREAK);
    exit(exit_code);
}