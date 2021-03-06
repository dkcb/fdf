/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/21 19:08:11 by dkocob        #+#    #+#                 */
/*   Updated: 2022/03/15 17:15:51 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# define X_REZ 1024
# define Y_REZ 768
# define R 0.0174533

struct	s_p {
	double			x;
	double			y;
	double			z;
	int				col;
};

struct	s_line {
	char			*line;
	struct s_line	*next;
};

struct	s_m {
	int				fd;
	int				szx;
	int				szy;
	int				szz;
	int				minz;
	int				maxz;
	float			un;
	int				rot;
	float			zoom;
	float			iso;
	struct s_p		start;
	struct s_line	*lhead;
	struct s_line	*cur;
};

struct	s_misc {
	int				c;
	int				i1;
	int				i2;
	int				i3;
};

struct	s_ln{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	col;
};

struct	s_br{
	int	sx;
	int	sy;
	int	dx;
	int	dy;
	int	err;
	int	e2;
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

struct	s_mouse {
	int				pr;
	int				px;
	int				py;
};

struct	s_data {
	void			*win;
	void			*mlx;
	struct s_p		*vs;
	struct s_mouse	c;
	struct s_m		m;
	struct s_misc	i;
	struct s_img	img;
	struct s_ln		ln;
};
void		assign_map_values(struct s_data *d);
void		img_clear(unsigned int col, struct s_data *d);
void		put_pixel(int x, int y, int col, struct s_data *d);
void		bresenham_(struct s_br *br, struct s_ln *ln, struct s_data *d);
int			put_line(struct s_ln *ln, struct s_data *d);
struct s_p	*map_init(struct s_data *d);
void		map_draw(int i, struct s_data *d);
void		map_apply_z(struct s_data *d);
void		map_rotate(struct s_data *d);
int			mouse_move(int x, int y, struct s_data *d);
int			mouse_release(int press, int x, int y, struct s_data *d);
int			mouse_press(int press, int x, int y, struct s_data *d);
void		render(struct s_data *d);
int			closehook(int keycode, struct s_data *d);
int			hooks(struct s_data *d);
int			window(struct s_data *d);
int			draw(struct s_data *d);
int			order_int(int *x1, int *y1, int *x2, int *y2);
int			get_next_line(int fd, char **line);
#endif
