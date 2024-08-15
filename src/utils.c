/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:46:43 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/10/04 14:24:40 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_mat(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
		free(mat[i]);
	free(mat);
}

void	ft_exit(char *str, char **mat, char **copy)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	if (mat)
		free_mat(mat);
	if (copy)
		free_mat(copy);
	exit(1);
}

char	**copy_mat(char **mat)
{
	int		size;
	char	**copy;
	char	*tmp;
	int		i;

	size = 0;
	while (mat[size])
		size++;
	copy = (char **)malloc(sizeof(char *) * (size + 1));
	if (!copy)
		ft_exit("Malloc error", mat, NULL);
	copy[size] = NULL;
	i = -1;
	while (++i < size)
	{
		tmp = ft_strdup(mat[i]);
		if (!tmp)
			ft_exit("Malloc error", mat, copy);
		copy[i] = tmp;
	}
	return (copy);
}

static void	create_mat(int fd, char **mat, int size)
{
	char	*tmp;
	int		i;

	i = -1;
	while (++i < size)
	{
		tmp = get_next_line(fd);
		if (i + 1 != size)
			mat[i] = ft_substr(tmp, 0, ft_strlen(tmp) - 1);
		else
			mat[i] = ft_substr(tmp, 0, ft_strlen(tmp));
		if (!mat[i])
		{
			free(tmp);
			ft_exit("Malloc error", mat, NULL);
		}
		free(tmp);
	}
}

char	**map_read(int fd, char *path)
{
	char	**mat;
	char	*tmp;
	int		size;

	size = 0;
	tmp = get_next_line(fd);
	if (tmp)
		size++;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp)
			size++;
	}
	mat = (char **)malloc(sizeof(char *) * (size + 1));
	close(fd);
	if (!mat)
		ft_exit("Malloc error", NULL, NULL);
	mat[size] = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit("Bad file descriptor", mat, NULL);
	create_mat(fd, mat, size);
	return (close(fd), mat);
}
