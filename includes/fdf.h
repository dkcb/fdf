/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 19:08:11 by dkocob        #+#    #+#                 */
/*   Updated: 2022/02/26 20:03:52 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define X_REZ 1024
#define Y_REZ 768
#define CONST 0.0174533

typedef struct s_node {
	int				x;
	int				y;
	int				z;
	unsigned int	col;
}	t_node;

typedef struct s_cube {
	int				startx;
	int				starty;
	int				side;
	int				rotx;
	int				roty;
	int 			rotz;
	unsigned int	col;
}	t_cube;

struct	s_cam {
	double			rotx;
	double			roty;
	double			rotz;
	double			zoom;
};

struct	s_p {
	double			x;
	double			y;
	double			z;
	int				col;
};

struct	s_v {
	struct s_p		orig;
	struct s_p		start;
	struct s_p		end;
	double			ang;
	double			len;
	int				col;
};

struct	s_line {
	char			*line;
	struct s_line	*next;
};

struct	s_map {
	int				size_x;
	int				size_y;
	int				size_z;
	int				minx;
	int				miny;
	int				maxx;
	int				maxy;
	int				un;
	int				rot;
	float			zoom;
	float			iso;
	struct s_node	start;
	struct s_node	*v;
	struct s_line	*lhead;
	struct s_line	*current;
};

struct	s_img {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				rx;
	int				ry;
};

struct	s_obj {
	int				x;
	int				y;
	int				col;
};

struct	s_mouse {
	int				pr;
	int				px;
	int				py;
	int				dfpx;
	int				dfpy;
	int				mrl;
};

struct	s_data {
	void			*win;
	void			*mlx;
	struct s_mouse	m;
	struct s_map	map;
	struct s_img	img;
	struct s_p		p;
	struct s_v		v;
	struct s_node	*vs;
};

int		center(struct s_data *d);
void	get_size(struct s_data *d);
void	draw_vector_struct(struct s_data *d);
void	img_clear(unsigned int col, struct s_data *d);
void	put_pixel(int x, int y, int col, struct s_data *d);
void	bresenham_ (int x1, int y1, int x2, int y2, int col, struct s_data *d);
int		put_line(int x1, int y1, int x2, int y2, int col, struct s_data *d);
void	map_draw(struct s_data *d);
void	map_apply_z(struct s_data *d);
void	map_rotate(struct s_data *d);
void	render(struct s_data *d);
void	bresenham_ (int x1, int y1, int x2, int y2, int col, struct s_data *d);
int		order_int(int *x1, int *y1, int *x2, int *y2);
int		closehook(int keycode, struct s_data *d);
int		mouse_move(int x, int y, struct s_data *d);
int		hooks(struct s_data *d);
int		window(struct s_data *d);
int		mouse_release(int press, int x, int y, struct s_data *d);
int		mouse_press(int press, int x, int y, struct s_data *d);
int		draw(struct s_data *d);
int		bresenham_RB(int sx, int sy, int ex, int ey, int col, struct s_data *d);
int		put_line(int sx, int sy, int ex, int ey, int col, struct s_data *d);
int		order_int(int *x1, int *y1, int *x2, int *y2);
int		get_next_line(int fd, char **line);
int		map_init(int fd, struct s_data *d);
int		build_frame (struct s_data *d);
int		put_object(struct s_data *d);
int		put_vector_br(int x1, int y1, double ang, double len, int col, struct s_data *d);
void	draw_vector_struct(struct s_data *d);
# endif
