/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:44:22 by rsandova          #+#    #+#             */
/*   Updated: 2020/02/11 17:10:31 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

t_flags	ft_flag_width(const char *format, t_flags flags)
{
	if (!flags.width)
	{
		flags.width = *format - '0';
		return (flags);
	}
	flags.width = (flags.width * 10) + *format - '0';
	return (flags);
}

t_flags	ft_flag_point_len(const char *format, t_flags flags)
{
	if (flags.p_len == -1)
	{
		flags.p_len = *format - '0';
		return (flags);
	}
	flags.p_len = (flags.p_len * 10) + *format - '0';
	return (flags);
}
