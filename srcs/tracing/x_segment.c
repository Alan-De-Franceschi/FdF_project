/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_segment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:12:11 by ade-fran          #+#    #+#             */
/*   Updated: 2024/02/21 18:12:15 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_first_octant(t_picture *img, t_dot dot, t_dot next_dot)
{
	int		dx;
	int		dy;
	int		e;
	int		color;
	t_rgb	d_color;

	e = next_dot.x - dot.x;
	dx = e * 2;
	dy = (next_dot.y - dot.y) * 2;
	color = dot.color;
	d_color = ft_compute_gradient(dot, next_dot);
	while (dot.x <= next_dot.x)
	{
		ft_put_pixel(img, dot.x, dot.y, color);
		color = ft_compute_color(dot, next_dot, d_color, color);
		dot.x += 1;
		e = e - dy;
		if (e <= 0)
		{
			dot.y += 1;
			e += dx;
		}
	}
}

static void	ft_second_octant(t_picture *img, t_dot dot, t_dot next_dot)
{
	int		dx;
	int		dy;
	int		e;
	int		color;
	t_rgb	d_color;

	e = next_dot.y - dot.y;
	dx = (next_dot.x - dot.x) * 2;
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
			dot.x += 1;
			e += dy;
		}
	}
}

static void	ft_seventh_octant(t_picture *img, t_dot dot, t_dot next_dot)
{
	int		dx;
	int		dy;
	int		e;
	int		color;
	t_rgb	d_color;

	e = dot.y - next_dot.y;
	dx = (next_dot.x - dot.x) * 2;
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
			dot.x += 1;
			e += dy;
		}
	}
}

static void	ft_eighth_octant(t_picture *img, t_dot dot, t_dot next_dot)
{
	int		dx;
	int		dy;
	int		e;
	int		color;
	t_rgb	d_color;

	e = next_dot.x - dot.x;
	dx = e * 2;
	dy = (dot.y - next_dot.y) * 2;
	color = dot.color;
	d_color = ft_compute_gradient(dot, next_dot);
	while (dot.x <= next_dot.x)
	{
		ft_put_pixel(img, dot.x, dot.y, color);
		color = ft_compute_color(dot, next_dot, d_color, color);
		dot.x += 1;
		e = e + dy;
		if (e >= 0)
		{
			dot.y -= 1;
			e -= dx;
		}
	}
}

void	ft_x_segment(t_picture *img, t_dot dot, t_dot next_dot)
{
	int	dx;
	int	dy;

	dx = next_dot.x - dot.x;
	dy = next_dot.y - dot.y;
	if (dot.y <= next_dot.y && dx > dy)
		ft_first_octant(img, dot, next_dot);
	else if (dot.y <= next_dot.y && dx <= dy)
		ft_second_octant(img, dot, next_dot);
	else if (dot.y >= next_dot.y && dx > ft_abs(dy))
		ft_eighth_octant(img, dot, next_dot);
	else if (dot.y >= next_dot.y && dx <= ft_abs(dy))
		ft_seventh_octant(img, dot, next_dot);
}
