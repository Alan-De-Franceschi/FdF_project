/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:11:16 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/05 17:11:19 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_serv *serv)
{
	if (key == 65307)
	{
		mlx_destroy_image(serv->mlx, serv->img);
		mlx_clear_window(serv->mlx, serv->win);
		mlx_destroy_window(serv->mlx, serv->win);
		mlx_destroy_display(serv->mlx);
		free(serv->mlx);
		free(serv->coordinates);
		exit(1);
	}
	return (1);
}

int	exit_hook(t_serv *serv)
{
	mlx_destroy_image(serv->mlx, serv->img);
	mlx_clear_window(serv->mlx, serv->win);
	mlx_destroy_window(serv->mlx, serv->win);
	mlx_destroy_display(serv->mlx);
	free(serv->mlx);
	free(serv->coordinates);
	exit(1);
}

int	ft_serv_manager(t_serv *serv, char *file)
{
	t_dot	*coordinates;

	coordinates = ft_dot_parsing(file);
	if (!coordinates)
		return (0);
	serv->coordinates = coordinates;
	serv->mlx = mlx_init();
	if (!serv->mlx)
		return (free(serv->coordinates), 0);
	serv->win = mlx_new_window(serv->mlx, 1280, 720, "MLX new window");
	if (!serv->win)
		return (free(serv->coordinates), free(serv->mlx), 0);
	return (1);
}

int	ft_img_manager(t_serv *serv, t_picture *img)
{
	img->img = mlx_new_image(serv->mlx, 1280, 720);
	if (!img->img)
		return (free(serv->coordinates), free(serv->mlx), 0);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->edn);
	if (!img->addr)
		return (free(img->img), free(serv->coordinates), free(serv->mlx), 0);
	serv->img = img->img;
	return (1);
}
