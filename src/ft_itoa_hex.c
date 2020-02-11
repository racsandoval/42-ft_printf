/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:12:51 by rsandova          #+#    #+#             */
/*   Updated: 2020/01/31 20:53:22 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_itoa_hex(unsigned int n)
{
	int				len;
	unsigned int	nbr;
	char			*resp;
	char			*base;

	len = (n == 0) ? 1 : 0;
	nbr = n;
	base = "0123456789abcdef";
	while (nbr > 0)
	{
		nbr /= 16;
		len++;
	}
	resp = malloc(len + 1);
	resp[len] = 0;
	len--;
	while (len >= 0)
	{
		resp[len] = base[(n % 16)];
		n /= 16;
		len--;
	}
	return (resp);
}
