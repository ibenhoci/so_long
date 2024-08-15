/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:42:19 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/09/17 12:49:51 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_pos	get_pos(t_info *info)
{
	int		i;
	int		j;
	t_pos	pos;

	i = -1;
	pos.x = 0;
	pos.y = 0;
	while (info->mat[++i])
	{
		j = -1;
		while (info->mat[i][++j])
		{
			if (info->mat[i][j] == 'P')
			{
				pos.x = i;
				pos.y = j;
				break ;
			}
		}
		if (info->mat[i][j] == 'P')
			break ;
	}
	return (pos);
}

static int	cond(t_info *info, t_pos pos)
{
	if (info->mat[pos.x][pos.y] == '1')
		return (0);
	else if (info->mat[pos.x][pos.y] == 'X')
		ft_ex(0, info, "You lost!");
	else if (info->mat[pos.x][pos.y] == 'E')
	{
		if (info->c_count == 0)
			ft_ex(0, info, "You won!");
		else
			return (0);
	}
	else if (info->mat[pos.x][pos.y] == 'C')
	{
		info->c_count--;
		return (1);
	}
	return (1);
}

static void	update_mat2(t_info *info, int direction, t_pos pos)
{
	if (direction == 3)
	{
		pos.y += 1;
		if (cond(info, pos))
		{
			info->mat[pos.x][pos.y - 1] = '0';
			info->mat[pos.x][pos.y] = 'P';
			print_map(info);
		}
	}
	else
	{
		pos.y -= 1;
		if (cond(info, pos))
		{
			info->mat[pos.x][pos.y + 1] = '0';
			info->mat[pos.x][pos.y] = 'P';
			print_map(info);
		}
	}
}

void	update_mat(t_info *info, int direction)
{
	t_pos	pos;

	pos = get_pos(info);
	if (direction == 1)
	{
		pos.x -= 1;
		if (cond(info, pos))
		{
			info->mat[pos.x + 1][pos.y] = '0';
			info->mat[pos.x][pos.y] = 'P';
			print_map(info);
		}
	}
	else if (direction == 2)
	{
		pos.x += 1;
		if (cond(info, pos))
		{
			info->mat[pos.x - 1][pos.y] = '0';
			info->mat[pos.x][pos.y] = 'P';
			print_map(info);
		}
	}
	else
		update_mat2(info, direction, pos);
}

void	ev_handler(mlx_key_data_t key, void *param)
{
	t_info	*info;

	info = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		ft_ex(0, info, NULL);
	else if ((key.key == MLX_KEY_UP || key.key == MLX_KEY_W)
		&& key.action == MLX_PRESS)
		update_mat(info, 1);
	else if ((key.key == MLX_KEY_DOWN || key.key == MLX_KEY_S)
		&& key.action == MLX_PRESS)
		update_mat(info, 2);
	else if ((key.key == MLX_KEY_RIGHT || key.key == MLX_KEY_D)
		&& key.action == MLX_PRESS)
		update_mat(info, 3);
	else if ((key.key == MLX_KEY_LEFT || key.key == MLX_KEY_A)
		&& key.action == MLX_PRESS)
		update_mat(info, 4);
}
