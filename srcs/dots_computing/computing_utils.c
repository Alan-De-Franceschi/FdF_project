/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computing_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:55:51 by ade-fran          #+#    #+#             */
/*   Updated: 2024/02/20 10:55:54 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_x_max(t_dot *coordinates)
{
	int	i;
	int	x_max;

	i = 0;
	x_max = coordinates[0].x;
	while (!coordinates[i].end)
	{
		if (coordinates[i].x > x_max)
			x_max = coordinates[i].x;
		i++;
	}
	return (x_max);
}

static int	ft_get_y_max(t_dot *coordinates)
{
	int	i;
	int	y_max;

	i = 0;
	y_max = coordinates[0].y;
	while (!coordinates[i].end)
	{
		if (coordinates[i].y > y_max)
			y_max = coordinates[i].y;
		i++;
	}
	return (y_max);
}

static int	ft_get_x_min(t_dot *coordinates)
{
	int	i;
	int	x_min;

	i = 0;
	x_min = coordinates[0].x;
	while (!coordinates[i].end)
	{
		if (coordinates[i].x < x_min)
			x_min = coordinates[i].x;
		i++;
	}
	return (x_min);
}

static int	ft_get_y_min(t_dot *coordinates)
{
	int	i;
	int	y_min;

	i = 0;
	y_min = coordinates[0].y;
	while (!coordinates[i].end)
	{
		if (coordinates[i].y < y_min)
			y_min = coordinates[i].y;
		i++;
	}
	return (y_min);
}

int	ft_get_extrems(int dot, t_dot *coordinates)
{
	if (dot == X_MAX)
		return (ft_get_x_max(coordinates));
	if (dot == X_MIN)
		return (ft_get_x_min(coordinates));
	if (dot == Y_MAX)
		return (ft_get_y_max(coordinates));
	if (dot == Y_MIN)
		return (ft_get_y_min(coordinates));
	return (0);
}
