/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:25:59 by ade-fran          #+#    #+#             */
/*   Updated: 2024/02/21 10:26:01 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_coordinates(t_dot *coordinates, int i, int x, int y)
{
	coordinates[i].x = x;
	coordinates[i].index_x = x;
	coordinates[i].y = y;
	coordinates[i].index_y = y;
	coordinates[i].end = 0;
}

void	ft_parsing_error(char **tab)
{
	ft_free_strtab(tab);
	ft_putstr_fd("Parsing: Map format error", 2);
}

int	ft_check_line_count(int nb_line)
{
	if (nb_line == -1)
		return (0);
	if (nb_line == 0)
	{
		ft_putstr_fd("Parsing: Map format error", 2);
		return (0);
	}
	return (1);
}
