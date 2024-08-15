/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:40:34 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/10/21 14:57:59 by ibenhoci         ###   ########.fr       */
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

static int	is_playable(char **mat, int x, int y, int *arr)
{
	if (mat[x][y] == 'C')
		(arr[0])--;
	if (mat[x][y] == 'E')
		(arr[1])--;
	else
	{
		mat[x][y] = '1';
		if (mat[x + 1][y] != '1' && mat[x + 1][y] != 'X')
			is_playable(mat, x + 1, y, arr);
		if (mat[x][y + 1] != '1' && mat[x][y + 1] != 'X')
			is_playable(mat, x, y + 1, arr);
		if (mat[x - 1][y] != '1' && mat[x - 1][y] != 'X')
			is_playable(mat, x - 1, y, arr);
		if (mat[x][y - 1] != '1' && mat[x][y - 1] != 'X')
			is_playable(mat, x, y - 1, arr);
	}
	return (arr[0]);
}

int	valid_map(char **mat)
{
	int		x;
	int		y;
	int		arr[2];
	char	**copy;

	arr[0] = valid_chars(mat);
	if (!arr[0] || !is_valid_rec(mat) || !valid_content(mat))
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
	arr[1] = 1;
	if (is_playable(copy, x, y, arr) != 0 || arr[1] > 0)
		return (free_mat(copy), 0);
	return (free_mat(copy), 1);
}
