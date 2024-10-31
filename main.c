/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:56:19 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/31 09:56:29 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_serv		serv;
	t_picture	img;

	if (!ft_check_args(argv[1], argc))
		return (1);
	if (!ft_serv_manager(&serv, argv[1]))
		return (1);
	if (!ft_img_manager(&serv, &img))
		return (1);
	mlx_key_hook(serv.win, deal_key, &serv);
	mlx_hook(serv.win, DestroyNotify, StructureNotifyMask, exit_hook, &serv);
	ft_tracing(&img, serv.coordinates);
	mlx_put_image_to_window(serv.mlx, serv.win, img.img, 0, 0);
	mlx_loop(serv.mlx);
	return (0);
}
