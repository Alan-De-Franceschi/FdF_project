/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y_segment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:12:30 by ade-fran          #+#    #+#             */
/*   Updated: 2024/02/21 18:12:31 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_third_octant(t_picture *img, t_dot dot, t_dot next_dot)
{
	int		dx;
	int		dy;
	int		e;
	int		color;
	t_rgb	d_color;

	e = next_dot.y - dot.y;
	dx = (dot.x - next_dot.x) * 2;
	dy = e * 2;
	color = dot.color;
	d_color = ft_compute_gradient(dot, next_dot);
	while (dot.y <= next_dot.y)
	{
		ft_put_pixel(img, dot.x, dot.y, color);
		color = ft_compute_color(dot, next_dot, d_color, color);
		dot.y += 1;
		e = e - dx;
		if (e <= 0)
		{
			dot.x -= 1;
			e += dy;
		}
	}
}

static void	ft_fourth_octant(t_picture *img, t_dot dot, t_dot next_dot)
{
	int		dx;
	int		dy;
	int		e;
	int		color;
	t_rgb	d_color;

	e = dot.x - next_dot.x;
	dx = e * 2;
	dy = (next_dot.y - dot.y) * 2;
	color = dot.color;
	d_color = ft_compute_gradient(dot, next_dot);
	while (dot.x >= next_dot.x)
	{
		ft_put_pixel(img, dot.x, dot.y, color);
		color = ft_compute_color(dot, next_dot, d_color, color);
		dot.x -= 1;
		e = e - dy;
		if (e <= 0)
		{
			dot.y += 1;
			e += dx;
		}
	}
}

static void	ft_fifth_octant(t_picture *img, t_dot dot, t_dot next_dot)
{
	int		dx;
	int		dy;
	int		e;
	int		color;
	t_rgb	d_color;

	e = dot.x - next_dot.x;
	dx = e * 2;
	dy = (dot.y - next_dot.y) * 2;
	color = dot.color;
	d_color = ft_compute_gradient(dot, next_dot);
	while (dot.x >= next_dot.x)
	{
		ft_put_pixel(img, dot.x, dot.y, color);
		color = ft_compute_color(dot, next_dot, d_color, color);
		dot.x -= 1;
		e = e + dy;
		if (e >= 0)
		{
			dot.y -= 1;
			e -= dx;
		}
	}
}

static void	ft_sixth_octant(t_picture *img, t_dot dot, t_dot next_dot)
{
	int		dx;
	int		dy;
	int		e;
	int		color;
	t_rgb	d_color;

	e = dot.y - next_dot.y;
	dx = (dot.x - next_dot.x) * 2;
	dy = e * 2;
	color = dot.color;
	d_color = ft_compute_gradient(dot, next_dot);
	while (dot.y >= next_dot.y)
	{
		ft_put_pixel(img, dot.x, dot.y, color);
		color = ft_compute_color(dot, next_dot, d_color, color);
		dot.y -= 1;
		e = e - dx;
		if (e <= 0)
		{
			dot.x -= 1;
			e += dy;
		}
	}
}

void	ft_y_segment(t_picture *img, t_dot dot, t_dot next_dot)
{
	int	dx;
	int	dy;

	dx = dot.x - next_dot.x;
	dy = ft_abs(dot.y - next_dot.y);
	if (dot.y <= next_dot.y && dx <= dy)
		ft_third_octant(img, dot, next_dot);
	else if (dot.y <= next_dot.y && dx > dy)
		ft_fourth_octant(img, dot, next_dot);
	else if (dot.y >= next_dot.y && dx > dy)
		ft_fifth_octant(img, dot, next_dot);
	else if (dot.y >= next_dot.y && dx <= dy)
		ft_sixth_octant(img, dot, next_dot);
}
