#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"
# include "Libft/libft.h"
# include <unistd.h>
# include "minilibx-linux/mlx.h"

# define WIN_HEIGT 1920
# define WIN_WIDHT 1080
# define MLX_ERROR 1
# define TRANS_FACTOR_X 10
# define TRANS_FACTOR_Y 10
# define ZOOM_IN 1.1
# define ZOOM_OUT 0.9

# define COLOR_RED 0xFF0000
# define COLOR_GREEN 0x00FF00
# define COLOR_YELLOW 0xFFFF00

typedef struct t_map
{
    int width;
    int height;
    int **z_matrix;
} t_map;

typedef struct t_camera
{
    int zoom;
    int x_offset;
    int y_offset;
    int translation_y;
    int translation_x;
    int mouse_zoom;
} t_camera;

typedef struct t_mlx
{
    void *mlx_ptr;
    void *win_ptr;
    int mouse_zoom;
    t_map map;
    t_camera camera;
    struct t_fdf *fdf;
} t_mlx;

typedef struct t_fdf
{
    t_map map;
    t_camera camera;
    int color;
    int translation_y;
    int translation_x;
    t_mlx mlx;
} t_fdf;

/*Commands.c*/
int key_handler(int key, t_fdf *fdf);
int close_win(t_mlx *mlx);

#endif
