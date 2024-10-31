/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:44:12 by ade-fran          #+#    #+#             */
/*   Updated: 2024/02/26 18:44:21 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_check_argc(int argc)
{
	if (argc < 2)
	{
		ft_putstr_fd("Args: Too few arguments", 2);
		return (0);
	}
	if (argc > 2)
	{
		ft_putstr_fd("Args: Too many arguments", 2);
		return (0);
	}
	return (1);
}

static int	ft_file_error(void)
{
	ft_putstr_fd("Args: Invalid filename", 2);
	return (0);
}

static int	ft_check_file(char *args)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (args[i++])
	{
		if (args[i] == '.')
		{
			flag = 1;
			i++;
			if (args[i++] != 'f')
				return (ft_file_error());
			if (args[i++] != 'd')
				return (ft_file_error());
			if (args[i++] != 'f')
				return (ft_file_error());
			break ;
		}
	}
	if (args[i] || flag == 0)
		return (ft_file_error());
	return (1);
}

int	ft_check_args(char *args, int argc)
{
	if (!ft_check_argc(argc))
		return (0);
	if (!ft_check_file(args))
		return (0);
	return (1);
}
