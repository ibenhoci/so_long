/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:32:52 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/10/07 12:45:05 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*x;

	if (size && SIZE_MAX / size < nmemb)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	x = malloc(nmemb * size);
	if (x == NULL)
		return (NULL);
	ft_bzero(x, nmemb * size);
	return (x);
}
