/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:21:33 by rsandova          #+#    #+#             */
/*   Updated: 2020/01/31 20:54:00 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*ft_u_itoa(unsigned int n)
{
	int				len;
	unsigned int	nbr;
	char			*resp;

	len = (n == 0) ? 1 : 0;
	nbr = n;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	resp = malloc(len + 1);
	resp[len] = 0;
	len--;
	while (len >= 0)
	{
		resp[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (resp);
}
