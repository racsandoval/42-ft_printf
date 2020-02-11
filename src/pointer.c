/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:26:48 by rsandova          #+#    #+#             */
/*   Updated: 2020/02/06 18:06:22 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

size_t	ft_is_point(size_t num, t_flags flags)
{
	char	*str;
	size_t	len;

	flags.ispointer = 1;
	str = ft_set_flags(ft_ltoa_base(num, "0123456789abcdef", 16), flags);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
