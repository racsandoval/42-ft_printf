/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:42:02 by rsandova          #+#    #+#             */
/*   Updated: 2020/01/25 19:30:51 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src,
					size_t dstsize)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < dstsize && i <= ft_strlen(src))
	{
		dst[i] = 0;
		i++;
	}
	return (ft_strlen(src));
}
