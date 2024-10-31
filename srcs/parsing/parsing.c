/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:24:15 by ade-fran          #+#    #+#             */
/*   Updated: 2024/02/12 20:24:17 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_free_all(t_dot *coordinates, char **line_tab)
{
	free(coordinates);
	ft_free_strtab(line_tab);
	ft_putstr_fd("Parsing: Map format error", 2);
}

static int	ft_check_map(char **line_tab)
{
	int		i;
	size_t	nb_dot;

	if (!line_tab)
		return (0);
	i = 0;
	nb_dot = ft_count_word(line_tab[0], " \n");
	while (line_tab[i])
	{
		if (ft_count_word(line_tab[i], " \n") != nb_dot)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_count_dot(char **line_tab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line_tab[i])
		count += ft_count_word(line_tab[i++], " \n");
	return (count);
}

static int	ft_get_coordinates(t_dot *coordinates, char **line_tab, int *error)
{
	int		i;
	int		x;
	int		y;
	char	**temp;

	i = 0;
	y = 0;
	while (line_tab[y])
	{
		temp = ft_split(line_tab[y], " \n");
		if (!temp)
			return (ft_free_all(coordinates, line_tab), 0);
		x = 0;
		while (temp[x])
		{
			ft_fill_coordinates(coordinates, i, x, y);
			coordinates[i].z = ft_atoi(temp[x], error);
			x++;
			i++;
		}
		y++;
		ft_free_strtab(temp);
	}
	coordinates[i].end = 1;
	return (1);
}

t_dot	*ft_dot_parsing(char const *file)
{
	t_dot	*coordinates;
	char	**line_tab;
	int		nb_dot;
	int		error;

	error = 0;
	line_tab = ft_read_file(file);
	if (!line_tab)
		return (NULL);
	if (!ft_check_map(line_tab))
		return (ft_parsing_error(line_tab), NULL);
	nb_dot = ft_count_dot(line_tab);
	coordinates = (t_dot *)malloc(sizeof(t_dot) * (nb_dot + 1));
	if (!coordinates)
		return (ft_free_strtab(line_tab), NULL);
	if (!ft_get_coordinates(coordinates, line_tab, &error))
		return (NULL);
	if (error)
		return (ft_free_all(coordinates, line_tab), NULL);
	if (!ft_fill_colors(coordinates))
		return (ft_free_all(coordinates, line_tab), NULL);
	return (ft_free_strtab(line_tab), coordinates);
}
