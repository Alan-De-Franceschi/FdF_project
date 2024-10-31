/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:35:26 by ade-fran          #+#    #+#             */
/*   Updated: 2024/02/27 15:35:28 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_rgb	ft_compute_gradient(t_dot dot, t_dot next_dot)
{
	int		dx;
	int		dy;
	int		dot_clr;
	int		next_dot_clr;
	t_rgb	d_color;

	dx = ft_abs(dot.x - next_dot.x);
	dy = ft_abs(dot.y - next_dot.y);
	dot_clr = dot.color;
	next_dot_clr = next_dot.color;
	if (dx > dy)
	{
		d_color.r = (ft_abs(ft_get_r(dot_clr) - ft_get_r(next_dot_clr))) / dx;
		d_color.g = (ft_abs(ft_get_g(dot_clr) - ft_get_g(next_dot_clr))) / dx;
		d_color.b = (ft_abs(ft_get_b(dot_clr) - ft_get_b(next_dot_clr))) / dx;
	}
	if (dx <= dy)
	{
		d_color.r = (ft_abs(ft_get_r(dot_clr) - ft_get_r(next_dot_clr))) / dy;
		d_color.g = (ft_abs(ft_get_g(dot_clr) - ft_get_g(next_dot_clr))) / dy;
		d_color.b = (ft_abs(ft_get_b(dot_clr) - ft_get_b(next_dot_clr))) / dy;
	}
	return (d_color);
}

int	ft_compute_color(t_dot dot, t_dot next_dot, t_rgb d_color, int color)
{
	if (dot.z == next_dot.z)
		return (color);
	if (dot.z < next_dot.z)
		return (ft_decrease_clr(color, d_color.r, d_color.g, d_color.b));
	return (ft_increment_clr(color, d_color.r, d_color.g, d_color.b));
}
