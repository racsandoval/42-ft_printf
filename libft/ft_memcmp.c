/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:29:10 by rsandova          #+#    #+#             */
/*   Updated: 2020/01/25 18:04:27 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*char_s1;
	unsigned char	*char_s2;

	if (n == 0)
		return (0);
	i = 0;
	char_s1 = (unsigned char *)s1;
	char_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (char_s1[i] != char_s2[i] || i + 1 == n)
			return (char_s1[i] - char_s2[i]);
		i++;
	}
	return (0);
}
