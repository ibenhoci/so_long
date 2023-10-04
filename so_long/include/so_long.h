/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:29:26 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/09/18 19:08:29 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libs/libft/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

typedef struct s_info	t_info;

typedef struct s_info
{
	char		**mat;
	int			c_count;
	int			m_count;	
	int			flag;	
	int			alive;
	mlx_t		*win;
	mlx_image_t	*bg;
	mlx_image_t	*p;
	mlx_image_t	*en;
	mlx_image_t	*ex;
	mlx_image_t	*c;
	mlx_image_t	*w;
	mlx_image_t	*sc;
}	t_info;

typedef struct s_pos	t_pos;
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

char			*get_next_line(int fd);
char			*ft_init(char *str);
char			*ft_join(char *str, char *buffer);
char			*create_line(char **str);
char			*ft_free(char **str, char *buffer);
char			**map_read(int fd, char *path);
int				valid_map(char **mat);
char			**copy_mat(char **mat);
void			free_mat(char **mat);
void			ft_exit(char *str, char **mat, char **copy);
void			init_s(char **mat, t_info *info);
mlx_image_t		*load_image(t_info *info, mlx_image_t *img, char *path);
void			print_map(t_info *info);
void			update_mat(t_info *info, int direction);
void			ft_ex(int ex_stat, t_info *info, char *str);
void			ev_handler(mlx_key_data_t key, void *param);
void			print_score(t_info *info, char *str);

#endif
