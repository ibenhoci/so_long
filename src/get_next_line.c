/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:37:29 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/09/10 15:36:43 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_free(char **str, char *buffer)
{
	if (*str != NULL)
		free(*str);
	*str = NULL;
	if (buffer != NULL)
		free(buffer);
	return (NULL);
}

char	*create_line(char **str)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while (str[0][i])
	{
		if (str[0][i] == '\n')
			break ;
		else
			i++;
	}
	line = ft_substr(*str, 0, i + 1);
	if (line == NULL)
		return (ft_free(str, line));
	tmp = *str;
	*str = ft_substr(tmp, i + 1, ft_strlen(tmp));
	free(tmp);
	if (str == NULL)
		return (free(line), NULL);
	return (line);
}

char	*ft_join(char *str, char *buffer)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(tmp, buffer);
	free(tmp);
	return (str);
}

char	*ft_init(char *str)
{
	if (!str)
		str = ft_strdup("");
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	int			n;

	str = ft_init(str);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL || str == NULL || fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(&str, buffer));
	n = 1;
	while (n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
			return (ft_free(&str, buffer));
		buffer[n] = '\0';
		str = ft_join(str, buffer);
		if (str == NULL)
			return (free(buffer), NULL);
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (ft_strlen(str) == 0)
		return (ft_free(&str, buffer));
	return (free(buffer), create_line(&str));
}
