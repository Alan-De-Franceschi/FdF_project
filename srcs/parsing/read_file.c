/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:57:25 by ade-fran          #+#    #+#             */
/*   Updated: 2024/02/20 10:57:27 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_open_error(int fd)
{
	if (fd < 0)
	{
		perror("Open");
		return (1);
	}
	return (0);
}

static int	ft_close_error(int fd)
{
	int	i;

	i = close(fd);
	if (i < 0)
	{
		perror("Close");
		return (1);
	}
	return (0);
}

static int	ft_count_line(char const *file)
{
	int		fd;
	int		nb_line;
	int		l;
	char	*str;

	nb_line = 0;
	l = 1;
	fd = open(file, O_RDONLY);
	if (ft_open_error(fd))
		return (-1);
	while (1)
	{
		str = ft_get_next_line(fd);
		if (!str || (l == 1 && str[0] == '\n'))
		{
			if (ft_close_error(fd))
				return (free(str), -1);
			return (free(str), nb_line);
		}
		if (str[0] != '\n')
			nb_line++;
		l++;
		free(str);
	}
}

static char	**ft_split_file(char const *file, int fd)
{
	int		size;
	int		i;
	char	**line_tab;

	i = 0;
	size = ft_count_line(file);
	if (!ft_check_line_count(size))
		return (NULL);
	line_tab = ft_calloc(size + 1, sizeof(char *));
	if (!line_tab)
		return (NULL);
	while (i < size)
	{
		line_tab[i] = ft_get_next_line(fd);
		if (!line_tab[i])
			return (ft_free_strtab(line_tab), NULL);
		if (line_tab[i][0] == '\n')
			return (ft_parsing_error(line_tab), NULL);
		i++;
	}
	line_tab[i] = NULL;
	return (line_tab);
}

char	**ft_read_file(char const *file)
{
	char	**line_tab;
	int		fd;

	fd = open(file, O_RDONLY);
	if (ft_open_error(fd))
		return (NULL);
	line_tab = ft_split_file(file, fd);
	if (!line_tab)
	{
		close(fd);
		return (NULL);
	}
	if (ft_close_error(fd))
		return (NULL);
	return (line_tab);
}
