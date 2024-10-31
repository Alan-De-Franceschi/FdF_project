/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:34:41 by ade-fran          #+#    #+#             */
/*   Updated: 2024/02/28 19:34:44 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_fill_index_z(t_dot *coordinates, t_list *lst)
{
	t_list	*temp;
	int		i;
	int		index_z;

	i = 0;
	while (!coordinates[i].end)
	{
		temp = lst;
		index_z = 0;
		while (temp)
		{
			if (coordinates[i].z == temp->data)
			{
				coordinates[i].index_z = index_z;
				break ;
			}
			temp = temp->next;
			index_z++;
		}
		i++;
	}
}

static int	ft_count_and_fill_floors(t_dot *coordinates)
{
	t_list	*floors;
	t_list	*new_node;
	int		i;
	int		count;

	floors = ft_lstnew(coordinates[0].z);
	if (!floors)
		return (0);
	i = 0;
	while (!coordinates[i].end)
	{
		if (!ft_int_in_lst(floors, coordinates[i].z))
		{
			new_node = ft_lstnew(coordinates[i].z);
			if (!new_node)
				return (ft_lstclear(&floors), 0);
			ft_lstadd_back(&floors, new_node);
		}
		i++;
	}
	count = ft_lstsize(floors);
	floors = ft_lstsort(floors);
	ft_fill_index_z(coordinates, floors);
	return (ft_lstclear(&floors), count);
}

static void	ft_fill_clrtab(int *clr_tab, int floors, int clr_min, int clr_max)
{
	int	i;
	int	dr;
	int	dg;
	int	db;

	i = 0;
	dr = (ft_get_r(clr_max) - ft_get_r(clr_min)) / floors;
	dg = (ft_get_g(clr_max) - ft_get_g(clr_min)) / floors;
	db = (ft_get_b(clr_max) - ft_get_b(clr_min)) / floors;
	while (i < floors)
	{
		clr_tab[i] = clr_min;
		clr_min = ft_increment_clr(clr_min, dr, dg, db);
		i++;
	}
}

static int	*ft_colors_tab(t_dot *coordinates)
{
	int	*colors_tab;
	int	nb_floors;

	nb_floors = ft_count_and_fill_floors(coordinates);
	if (nb_floors <= 0)
		return (NULL);
	colors_tab = malloc(sizeof(int) * nb_floors);
	if (!colors_tab)
		return (NULL);
	ft_fill_clrtab(colors_tab, nb_floors, 0x00FB335B, 0x003585CD);
	return (colors_tab);
}

int	ft_fill_colors(t_dot *coordinates)
{
	int	i;
	int	*colors_tab;

	i = 0;
	colors_tab = ft_colors_tab(coordinates);
	if (!colors_tab)
		return (0);
	while (!coordinates[i].end)
	{
		coordinates[i].color = colors_tab[coordinates[i].index_z];
		i++;
	}
	return (free(colors_tab), 1);
}
