/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:43:04 by rsandova          #+#    #+#             */
/*   Updated: 2020/01/25 17:56:50 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
						int c, size_t n)
{
	size_t				i;
	unsigned char		*dst_char;
	const unsigned char *src_char;

	i = 0;
	dst_char = (unsigned char *)dst;
	src_char = (unsigned char *)src;
	while (i < n)
	{
		dst_char[i] = src_char[i];
		if (src_char[i] == (unsigned char)c)
		{
			return ((void *)&dst[i + 1]);
		}
		i++;
	}
	return (0);
}
