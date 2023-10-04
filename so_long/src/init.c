/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:00:51 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/09/10 18:30:51 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	valid_chars(char **mat)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			if (mat[i][j] != 'P' && mat[i][j] != 'C' && mat[i][j] != 'E'
					&& mat[i][j] != '0' && mat[i][j] != '1' && mat[i][j] != 'X')
				return (0);
			if (mat[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static int	is_valid_rec(char **mat)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(mat[0]);
	while (mat[i])
		if (ft_strlen(mat[i++]) != (size_t)len)
			return (0);
	i--;
	j = -1;
	while (mat[i][++j])
		if (mat[i][j] != '1' || mat[0][j] != '1')
			return (0);
	j = len - 1;
	i = -1;
	while (mat[++i])
		if (mat[i][j] != '1' || mat[i][0] != '1')
			return (0);
	return (1);
}

static int	valid_content(char **mat)
{
	int	i;
	int	j;
	int	c;
	int	p;

	c = 0;
	p = 0;
	i = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			if (mat[i][j] == 'P' || mat[i][j] == 'E')
				p++;
			else if (mat[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (p != 2 || c < 1)
		return (0);
	return (1);
}

static int	is_playable(char **mat, int x, int y, int *c_count)
{
	if (mat[x][y] == 'C')
		(*c_count)--;
	if (mat[x][y] == 'E')
		(*c_count)--;
	else
	{
		mat[x][y] = '1';
		if (mat[x + 1][y] != '1' && mat[x + 1][y] != 'X')
			is_playable(mat, x + 1, y, c_count);
		if (mat[x - 1][y] != '1' && mat[x - 1][y] != 'X')
			is_playable(mat, x - 1, y, c_count);
		if (mat[x][y + 1] != '1' && mat[x][y + 1] != 'X')
			is_playable(mat, x, y + 1, c_count);
		if (mat[x][y - 1] != '1' && mat[x][y - 1] != 'X')
			is_playable(mat, x, y - 1, c_count);
	}
	return (*c_count);
}

int	valid_map(char **mat)
{
	int		x;
	int		y;
	int		count;
	char	**copy;

	count = valid_chars(mat);
	if (!count || !is_valid_rec(mat) || !valid_content(mat))
		return (0);
	x = -1;
	while (mat[++x])
	{
		y = -1;
		while (mat[x][++y])
		{
			if (mat[x][y] == 'P')
				break ;
		}
		if (mat[x][y] == 'P')
			break ;
	}
	copy = copy_mat(mat);
	if (is_playable(copy, x, y, &count) > -1)
		return (free_mat(copy), 0);
	return (free_mat(copy), 1);
}
