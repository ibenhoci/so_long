/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:31:16 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/10/21 15:11:14 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_score(t_info *info, char *str)
{
	ft_putstr_fd(str, 1);
	ft_putnbr_fd(++info->m_count, 1);
	ft_putstr_fd("\n", 1);
}

void	ft_ex(int ex_stat, t_info *info, char *str)
{
	if (str)
	{
		ft_putstr_fd(str, 1);
		ft_putstr_fd("\n", 1);
	}
	mlx_terminate(info->win);
	free_mat(info->mat);
	exit(ex_stat);
}

static int	check_argname(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i < 4)
		return (0);
	if (!ft_strncmp(&str[i - 4], ".ber", 5))
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**mat;
	t_info	info;

	if (argc != 2)
		return (ft_putstr_fd("Bad usage\n", 1), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || !check_argname(argv[1]))
		return (ft_putstr_fd("Invalid file\n", 1), 0);
	mat = map_read(fd, argv[1]);
	if (!mat)
		return (ft_putstr_fd("Invalid map\n", 1), 0);
	if (!valid_map(mat))
		return (free_mat(mat), ft_putstr_fd("Invalid map\n", 1), 0);
	init_s(mat, &info);
	mlx_key_hook(info.win, ev_handler, &info);
	mlx_loop(info.win);
	mlx_terminate(info.win);
	free_mat(mat);
	return (0);
}
