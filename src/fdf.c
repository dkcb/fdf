/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/20 17:54:41 by dkocob        #+#    #+#                 */
/*   Updated: 2021/11/20 23:23:38 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*image;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	int x = 0;
	int y = 1;

	vars.mlx = mlx_init();


	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// while (x++ < 600 && y++)
	// {
	// 	my_mlx_pixel_put(&img, x, x, 0x00FF0000);
	// 	if (x * x < 1080 && y < 1080)
	// 		my_mlx_pixel_put(&img, x * x, y, 0x00FF0000 + x);
	// 	my_mlx_pixel_put(&img, 1020 - x, 1080 - x, 0x00FF0000);
	// 	my_mlx_pixel_put(&img,  x + x, x, 0x00FF0000 - x);
	// }
	while (x++ < 1920)
	{
		y = (x * x) / 1000;
		if (x < 1920 && y < 1080)
			my_mlx_pixel_put(&img, 1920 - x, 1080 - y, 0x00FF0000 / x);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
