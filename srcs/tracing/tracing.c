/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:53:56 by ade-fran          #+#    #+#             */
/*   Updated: 2024/02/20 10:53:58 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_max_index_x(t_dot *coordinates)
{
	int	i;
	int	i_max;

	i = 0;
	i_max = coordinates[0].index_x;
	while (!coordinates[i].end)
	{
		if (coordinates[i].index_x > i_max)
			i_max = coordinates[i].index_x;
		i++;
	}
	return (i_max);
}

static int	ft_max_index_y(t_dot *coordinates)
{
	int	i;
	int	i_max;

	i = 0;
	i_max = coordinates[0].index_y;
	while (!coordinates[i].end)
	{
		if (coordinates[i].index_y > i_max)
			i_max = coordinates[i].index_y;
		i++;
	}
	return (i_max);
}

void	ft_tracing(t_picture *img, t_dot *coordinates)
{
	int		i;
	int		index_y;
	int		x_max;
	int		y_max;
	t_dot	nl_dot;

	x_max = ft_max_index_x(coordinates) + 1;
	y_max = ft_max_index_y(coordinates);
	i = 0;
	ft_dots_compute(coordinates);
	while (!coordinates[i].end)
	{
		index_y = coordinates[i].index_y;
		if (!coordinates[i + 1].end && index_y == coordinates[i + 1].index_y)
			ft_x_segment(img, coordinates[i], coordinates[i + 1]);
		if (coordinates[i].index_y < y_max)
		{
			nl_dot = coordinates[i + x_max];
			ft_y_segment(img, coordinates[i], nl_dot);
		}
		i++;
	}
}
