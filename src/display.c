/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:42:35 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/09/17 13:33:40 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

mlx_image_t	*load_image(t_info *info, mlx_image_t *img, char *path)
{
	xpm_t				*xpm;
	mlx_image_t			*image;

	if (img)
		mlx_delete_image(info->win, img);
	xpm = mlx_load_xpm42(path);
	if (!xpm)
		ft_ex(1, info, "Could not load the image!");
	image = mlx_texture_to_image(info->win, &xpm->texture);
	mlx_delete_xpm42(xpm);
	if (!image)
		ft_ex(1, info, "Could not convert the image!");
	return (image);
}

static void	print_map2(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (info->mat[++i])
	{
		j = -1;
		while (info->mat[i][++j])
		{
			if (info->mat[i][j] == 'P')
				mlx_image_to_window(info->win, info->p, j * 45, i * 45);
			if (info->mat[i][j] == 'E')
				mlx_image_to_window(info->win, info->ex, j * 45, i * 45);
			if (info->mat[i][j] == 'C')
				mlx_image_to_window(info->win, info->c, j * 45, i * 45);
			if (info->mat[i][j] == '1')
				mlx_image_to_window(info->win, info->w, j * 45, i * 45);
		}
	}
}

void	print_map(t_info *info)
{
	int		i;
	int		j;

	info->bg = load_image(info, info->bg, "assets/bg.xpm42");
	info->p = load_image(info, info->p, "assets/p.xpm42");
	info->ex = load_image(info, info->ex, "assets/ex.xpm42");
	info->c = load_image(info, info->c, "assets/c.xpm42");
	info->w = load_image(info, info->w, "assets/w.xpm42");
	i = -1;
	while (info->mat[++i])
	{
		j = -1;
		while (info->mat[i][++j])
			mlx_image_to_window(info->win, info->bg, j * 45, i * 45);
	}
	print_score(info, "Number of moves: ");
	print_map2(info);
}

void	init_s(char **mat, t_info *info)
{
	int	i;
	int	j;

	info->c_count = 0;
	i = -1;
	while (mat[++i])
	{
		j = -1;
		while (mat[i][++j])
		{
			if (mat[i][j] == 'C')
				info->c_count++;
		}
	}
	info->flag = 0;
	info->mat = mat;
	info->m_count = -1;
	info->alive = 1;
	info->win = mlx_init(j * 45, i * 45, "So_Long", false);
	print_map(info);
}
