/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:07:47 by rsandova          #+#    #+#             */
/*   Updated: 2020/01/23 19:08:37 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_itoa(int n, int count, char *str)
{
	unsigned int	num;

	str[count] = 0;
	count--;
	num = (n > 0) ? n : -n;
	while (num)
	{
		str[count] = (num % 10) + '0';
		num /= 10;
		count--;
	}
	if (!count)
		str[count] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int				count;
	unsigned int	num;
	char			*str;

	count = (n > 0) ? 0 : 1;
	num = (n > 0) ? n : -n;
	if (n == 0)
	{
		if (!(str = malloc(count + 1)))
			return (NULL);
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	while (num)
	{
		count++;
		num /= 10;
	}
	if (!(str = malloc(count + 1)))
		return (NULL);
	return (make_itoa(n, count, str));
}
