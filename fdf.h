/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:56:56 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/31 09:56:57 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# define SQRT_2 1.414214
# define SQRT_6 2.449490
# define SQRT_2_PER_3 0.816497

typedef struct s_serv
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*coordinates;
}	t_serv;

typedef struct s_picture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		edn;
}	t_picture;

typedef struct s_dot
{
	int	x;
	int	y;
	int	z;
	int	index_x;
	int	index_y;
	int	index_z;
	int	color;
	int	end;
}	t_dot;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

enum e_extrems
{
	X_MAX = 0,
	X_MIN = 1,
	Y_MAX = 2,
	Y_MIN = 3
};

int		ft_check_args(char *args, int argc);

int		deal_key(int key, t_serv *serv);
int		exit_hook(t_serv *serv);
int		ft_serv_manager(t_serv *serv, char *file);
int		ft_img_manager(t_serv *serv, t_picture *img);

char	**ft_read_file(char const *file);
int		ft_check_line_count(int nb_line);
t_dot	*ft_dot_parsing(char const *file);
void	ft_fill_coordinates(t_dot *coordinates, int i, int x, int y);
int		ft_fill_colors(t_dot *coordinates);
void	ft_parsing_error(char **tab);

void	ft_dots_compute(t_dot *coordinates);
int		ft_get_extrems(int dot, t_dot *coordinates);

void	ft_x_segment(t_picture *img, t_dot dot, t_dot next_dot);
void	ft_y_segment(t_picture *img, t_dot dot, t_dot next_dot);
void	ft_tracing(t_picture *img, t_dot *coordinates);

void	ft_put_pixel(t_picture *img, int x, int y, int color);
t_rgb	ft_compute_gradient(t_dot dot, t_dot next_dot);
int		ft_compute_color(t_dot dot, t_dot next_dot, t_rgb d_color, int color);
int		ft_increment_clr(int clr, int dr, int dg, int db);
int		ft_decrease_clr(int clr, int dr, int dg, int db);
int		ft_get_t(int trgb);
int		ft_get_r(int trgb);
int		ft_get_g(int trgb);
int		ft_get_b(int trgb);

#endif
