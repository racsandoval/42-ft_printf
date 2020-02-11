/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:51:28 by rsandova          #+#    #+#             */
/*   Updated: 2020/02/06 18:00:55 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

char	*ft_ltoa_base(size_t n, char *base, size_t b_len)
{
	int				len;
	size_t			nbr;
	char			*resp;

	len = (n) ? 0 : 1;
	nbr = n;
	while (nbr > 0)
	{
		len++;
		nbr /= b_len;
	}
	len += 2;
	resp = malloc(len + 1);
	resp[len--] = 0;
	while (len >= 2)
	{
		resp[len] = base[n % b_len];
		n /= b_len;
		len--;
	}
	resp[0] = '0';
	resp[1] = 'x';
	return (resp);
}
