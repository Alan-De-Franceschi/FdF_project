/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:07:27 by ade-fran          #+#    #+#             */
/*   Updated: 2024/02/21 18:07:29 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_picture *img, int x, int y, int color)
{
	char	*dst;

	dst = (*img).addr + (y * (*img).len + x * ((*img).bpp / 8));
	*(unsigned int *)dst = color;
}
