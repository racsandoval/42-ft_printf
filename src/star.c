/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:33:24 by rsandova          #+#    #+#             */
/*   Updated: 2020/02/11 17:10:09 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

t_flags	ft_check_star(t_flags flags, va_list ap)
{
	if (flags.star_w)
		flags.width = va_arg(ap, int);
	if (flags.star_p)
		flags.p_len = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.width *= -1;
		flags.minus = 1;
		flags.zero = 0;
	}
	return (flags);
}
