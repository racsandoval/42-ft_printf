/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:00:25 by rsandova          #+#    #+#             */
/*   Updated: 2020/01/21 18:25:22 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src,
					size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dstsize && dst[i])
	{
		i++;
	}
	j = 0;
	while (i + j + 1 < dstsize && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = 0;
	return (i + ft_strlen(src));
}
