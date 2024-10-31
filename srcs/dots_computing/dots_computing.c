/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_computing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:56:37 by ade-fran          #+#    #+#             */
/*   Updated: 2024/02/17 18:56:39 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_z_max(t_dot *coordinates)
{
	int	i;
	int	z_max;

	i = 0;
	z_max = coordinates[0].z;
	while (!coordinates[i].end)
	{
		if (coordinates[i].z > z_max)
			z_max = coordinates[i].z;
		i++;
	}
	return (z_max);
}

static int	ft_get_z_min(t_dot *coordinates)
{
	int	i;
	int	z_min;

	i = 0;
	z_min = coordinates[0].x;
	while (!coordinates[i].end)
	{
		if (coordinates[i].z < z_min)
			z_min = coordinates[i].z;
		i++;
	}
	return (z_min);
}

static void	ft_scale_compute(t_dot *coordinates)
{
	int	i;
	int	x_max;
	int	y_max;
	int	z_max;
	int	z_min;

	i = 0;
	x_max = ft_get_extrems(X_MAX, coordinates);
	y_max = ft_get_extrems(Y_MAX, coordinates);
	z_max = ft_get_z_max(coordinates);
	z_min = ft_get_z_min(coordinates);
	while (!coordinates[i].end)
	{
		if (z_max - z_min >= (720 * 5 / 100))
			coordinates[i].z /= (z_max - z_min) * 5 / 100;
		else if (z_max - z_min <= (1280 * 85 / 100) / x_max)
			coordinates[i].z *= 5;
		coordinates[i].x *= (1280 * 85 / 100) / x_max;
		coordinates[i++].y *= (720 * 85 / 100) / y_max;
	}
}

static void	ft_iso_compute(t_dot *coordinates)
{
	int	i;
	int	x;
	int	y;
	int	z;
	int	z0;

	i = 0;
	z0 = coordinates[0].z;
	ft_scale_compute(coordinates);
	while (!coordinates[i].end)
	{
		x = coordinates[i].x;
		y = coordinates[i].y;
		z = coordinates[i].z - z0;
		coordinates[i].x = (SQRT_2 / 2.0) * (x - y);
		coordinates[i++].y = ft_abs(SQRT_2_PER_3 * z - 1 / SQRT_6 * (x + y));
	}
}

void	ft_dots_compute(t_dot *coordinates)
{
	int	i;
	int	x_max;
	int	x_min;
	int	y_max;
	int	y_min;

	i = 0;
	ft_iso_compute(coordinates);
	x_max = ft_get_extrems(X_MAX, coordinates);
	x_min = ft_get_extrems(X_MIN, coordinates);
	y_max = ft_get_extrems(Y_MAX, coordinates);
	y_min = ft_get_extrems(Y_MIN, coordinates);
	while (!coordinates[i].end)
	{
		coordinates[i].x += (1280 - x_min) + ((1280 - (x_max - x_min)) / 2);
		coordinates[i++].y += (720 - (y_max - y_min)) / 2;
	}
}
