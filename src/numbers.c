/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:31:55 by rsandova          #+#    #+#             */
/*   Updated: 2020/02/07 18:32:17 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

size_t	ft_is_nbr(int n, t_flags flags)
{
	char	*str;
	size_t	len;

	flags.isnum = 1;
	str = ft_set_flags(ft_itoa(n), flags);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

size_t	ft_is_uint(unsigned int n, t_flags flags)
{
	char	*str;
	size_t	len;

	flags.isnum = 1;
	str = ft_set_flags(ft_u_itoa(n), flags);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

size_t	ft_is_hex(unsigned int n, char c, t_flags flags)
{
	char	*str;
	size_t	len;

	flags.isnum = 1;
	str = ft_set_flags(ft_itoa_hex(4294967295 + 1 + n), flags);
	len = ft_strlen(str);
	if (c == 'X')
		ft_str_toupper(str);
	ft_putstr(str);
	free(str);
	return (len);
}
