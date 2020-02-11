/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:45:04 by rsandova          #+#    #+#             */
/*   Updated: 2020/02/11 17:15:51 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

t_flags	ft_initialize_flags(void)
{
	t_flags	flags;

	flags.width = 0;
	flags.zero = 0;
	flags.p = 0;
	flags.p_len = 0;
	flags.minus = 0;
	flags.isnum = 0;
	flags.ispointer = 0;
	flags.star_w = 0;
	flags.star_p = 0;
	return (flags);
}

size_t	print_char(char format)
{
	ft_putchar_fd(format, 1);
	return (1);
}

size_t	ft_check_convs(const char *format, va_list ap, t_flags flags)
{
	if (*format == 's')
		return (ft_is_str(va_arg(ap, char*), flags));
	else if (*format == 'd' || *format == 'i')
		return (ft_is_nbr(va_arg(ap, int), flags));
	else if (*format == 'c')
		return (ft_is_char(va_arg(ap, int), flags));
	else if (*format == 'p')
		return (ft_is_point(va_arg(ap, size_t), flags));
	else if (*format == 'u')
		return (ft_is_uint(va_arg(ap, unsigned int), flags));
	else if (*format == 'x' || *format == 'X')
		return (ft_is_hex(va_arg(ap, int), *format, flags));
	else if (*format == '%')
		return (ft_is_percent('%', flags));
	return (0);
}

t_flags	ft_check_flags(const char *format, t_flags flags)
{
	if (*format == '0' && !flags.width)
		flags.zero = 1;
	if (*format == '.')
		flags.p = 1;
	if (*format == '-')
		flags.minus = 1;
	if (*format == '*' && !flags.p)
		flags.star_w = 1;
	if (*format == '*' && flags.p)
		flags.star_p = 1;
	if (ft_isdigit(*format) && !flags.p)
		flags = ft_flag_width(format, flags);
	if (ft_isdigit(*format) && flags.p)
		flags = ft_flag_point_len(format, flags);
	return (flags);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		len;
	t_flags		flags;

	if (!format)
		return (0);
	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			flags = ft_initialize_flags();
			while (ft_strchr(FLAGS, *(format + 1)))
				flags = ft_check_flags(++format, flags);
			if (!ft_strchr(SYMBOLS, *(format + 1)))
				return (0);
			flags = ft_check_star(flags, ap);
			len += ft_check_convs(++format, ap, flags);
		}
		else
			len += print_char(*format);
		format++;
	}
	return (len);
}
