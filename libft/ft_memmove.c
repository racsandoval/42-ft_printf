/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:00:48 by rsandova          #+#    #+#             */
/*   Updated: 2020/01/25 19:41:40 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst_char;
	const unsigned char *src_char;

	dst_char = (unsigned char *)dst;
	src_char = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (dst_char > src_char)
	{
		while (len--)
			dst_char[len] = src_char[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst_char[i] = src_char[i];
			i++;
		}
	}
	return (dst);
}
