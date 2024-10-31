/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_trgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:07:27 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/05 17:07:30 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	ft_get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	ft_get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	ft_get_b(int trgb)
{
	return (trgb & 0xFF);
}
