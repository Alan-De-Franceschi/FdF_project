/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:02:08 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/05 17:02:11 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_increment_clr(int clr, int dr, int dg, int db)
{
	int	clr_t;
	int	clr_r;
	int	clr_g;
	int	clr_b;

	clr_t = ft_get_t(clr);
	clr_r = ft_get_r(clr);
	clr_g = ft_get_g(clr);
	clr_b = ft_get_b(clr);
	clr_r += dr;
	clr_g += dg;
	clr_b += db;
	return (clr_t << 24 | clr_r << 16 | clr_g << 8 | clr_b);
}

int	ft_decrease_clr(int clr, int dr, int dg, int db)
{
	int	clr_t;
	int	clr_r;
	int	clr_g;
	int	clr_b;

	clr_t = ft_get_t(clr);
	clr_r = ft_get_r(clr);
	clr_g = ft_get_g(clr);
	clr_b = ft_get_b(clr);
	clr_r -= dr;
	clr_g -= dg;
	clr_b -= db;
	return (clr_t << 24 | clr_r << 16 | clr_g << 8 | clr_b);
}
