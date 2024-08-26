/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaakson <alaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:05:15 by alaakson          #+#    #+#             */
/*   Updated: 2024/08/26 08:30:53 by alaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int print_error(char *message);

void    init_map(t_map *map, int width, int height)
{
    int i;

    i = 0;
    map->width = width;
    map->height = height;
    map->z_matrix = malloc(height * sizeof(int *));
    if (!map->z_matrix)
    {
        print_error("%s Sumting wong\n");
    }
    while (i < height)
    {
        map->z_matrix[i] = malloc(width * sizeof(int));
        if (!map->z_matrix[i])
        {
            free(map->z_matrix[i]);
        }
        i++;
    }
}

void    init_camera(t_camera *camera)
{
    camera->zoom = 1;
    camera->x_offset = 0;
    camera->y_offset = 0;
    camera->translation_x = 0;
    camera->translation_y = 0;
}

void    init_mlx(t_mlx *mlx, void *mlx_ptr, void *win_ptr)
{
    mlx->mlx_ptr = mlx_ptr;
    mlx->win_ptr = win_ptr;
    init_map(&mlx->map, 0, 0);
    init_camera(&mlx->camera);
}

void init_fdf(t_fdf *fdf, void *mlx_ptr, void *win_ptr)
{
    init_mlx(&fdf->mlx, mlx_ptr, win_ptr);
    fdf->color = 0xFFFFFF;
}
void free_map(t_map *map)
{
    int     i;

    i = 0;
    while (i < map->height)
    {
        free(map->z_matrix[i]);
        i++;
    }
    free(map->z_matrix);
}

int print_error(char *message)
{
    ft_printf("%s\n", message);
    exit (1);
}
int main(int argc, char **argv)
{
    t_fdf fdf;
    void    *mlx_ptr;
    void    *win_ptr;

    if (argc != 2)
    {
       print_error("Wrong number of args\nWe need 2 args!");
       return (1);
    }
    mlx_ptr = mlx_init();
    if (!mlx_ptr)
    {
        print_error("Failed initialize MinilibX.\n");
        return (1);
    }
    init_fdf(&fdf, mlx_ptr, win_ptr);
    mlx_loop(mlx_ptr);
    free_map(&fdf.mlx.map);
    return (0);
}
