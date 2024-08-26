/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaakson <alaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:05:13 by alaakson          #+#    #+#             */
/*   Updated: 2024/08/26 08:28:14 by alaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    handles(t_mlx *mlx)
{
    mlx_key_hook(mlx->win_ptr, key_handler, mlx);
    mlx_hook(mlx->win_ptr, 17, 0, close_win, mlx);
    mlx_hook(mlx->win_ptr, 4, 0, close_win, mlx);
}

int close_win(t_mlx *mlx)
{
    mlx_destroy_window(mlx->win_ptr, mlx->mlx_ptr);
    exit (0);
}

int key_handler(int key, t_fdf *fdf)
{
    if (key == 53)
        close_win(&fdf->mlx);
    else if ((key == 13) || (key == 126))
        fdf->translation_y -= TRANS_FACTOR_Y;
    else if ((key == 1) || (key == 125))
        fdf->translation_y -= TRANS_FACTOR_Y;
    else if ((key == 0) || (key == 123 ))
        fdf->translation_x += TRANS_FACTOR_X;
    else if ((key == 2) || (key == 124))
        fdf->translation_x += TRANS_FACTOR_X;
    return (0);
}

int mouse(int mouse_usage, int x, int y, t_mlx *mlx)
{
    (void) x;
    (void) y;
    if (mouse_usage == 4)
        mlx->mouse_zoom *= ZOOM_IN;
    else if (mouse_usage == 5)
        mlx->mouse_zoom /= ZOOM_OUT;
    return (0);
}
