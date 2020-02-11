/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:05:02 by rsandova          #+#    #+#             */
/*   Updated: 2020/02/11 17:12:19 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

char	*ft_set_width(char *str, int width, int zero)
{
	char	*new_str;
	int		len;

	if (width <= (int)ft_strlen(str))
		return (str);
	len = (int)ft_strlen(str) - 1;
	new_str = (char	*)malloc(width + 1);
	new_str[width--] = 0;
	while (len >= 0)
		new_str[width--] = str[len--];
	while (width >= 0)
		new_str[width--] = (zero) ? '0' : ' ';
	free(str);
	return (new_str);
}

char	*ft_set_width_point(char *str, int width, int zero, int p_len)
{
	char	*new_str;
	int		len;

	if (width <= (int)ft_strlen(str))
		return (str);
	zero = (p_len >= 0 || (p_len < 0 && !zero)) ? 0 : 1;
	len = (int)ft_strlen(str) - 1;
	new_str = (char	*)malloc(width + 1);
	new_str[width--] = 0;
	while (len >= 0)
		new_str[width--] = str[len--];
	while (width >= 0)
		new_str[width--] = (zero) ? '0' : ' ';
	free(str);
	return (new_str);
}

char	*ft_set_minus_width(char *str, int width)
{
	char	*new_str;
	int		len;

	if (width <= (int)ft_strlen(str))
		return (str);
	len = 0;
	new_str = (char *)malloc(width + 1);
	while (len < (int)ft_strlen(str))
	{
		new_str[len] = str[len];
		len++;
	}
	while (len < width)
		new_str[len++] = ' ';
	new_str[len] = '\0';
	free(str);
	return (new_str);
}

char	*ft_set_neg_width(char *str, int width)
{
	char	*new_str;
	int		len;
	int		minus;

	if ((str[0] != '-' && width <= (int)ft_strlen(str))
		|| (str[0] == '-' && width <= (int)ft_strlen(str) - 1))
		return (str);
	minus = (str[0] == '-') ? 1 : 0;
	new_str = (char *)malloc(width + 1);
	len = (int)ft_strlen(str) - 1;
	new_str[width--] = 0;
	while (len >= minus)
		new_str[width--] = str[len--];
	while ((int)width >= minus)
		new_str[width--] = '0';
	if (minus)
		new_str[0] = '-';
	free(str);
	return (new_str);
}

char	*ft_set_flags(char *str, t_flags flags)
{
	if (flags.p && flags.isnum && flags.p_len > 0)
		str = ft_set_point_num(str, flags.p_len);
	else if (flags.p && flags.isnum && flags.zero && flags.p_len < 0 &&
			flags.width > (int)ft_strlen(str))
		str = ft_set_point_num(str, flags.width - 1);
	else if (flags.p && flags.isnum && !flags.p_len)
		str = ft_set_null_point(str);
	else if (flags.p && flags.ispointer && flags.p_len >= 0)
		str = ft_set_point_pointer(str, flags.p_len);
	else if (flags.p && !flags.isnum && !flags.ispointer && flags.p_len >= 0)
		str = ft_set_point_str(str, flags.p_len);
	if (flags.width && !flags.minus && (!flags.isnum || !flags.zero))
		str = ft_set_width(str, flags.width, flags.zero);
	else if (flags.width && flags.zero && flags.isnum &&
			!flags.p && !flags.minus)
		str = ft_set_neg_width(str, flags.width);
	else if (flags.width && flags.zero && flags.isnum &&
			flags.p && !flags.minus)
		str = ft_set_width_point(str, flags.width, flags.zero, flags.p_len);
	else if (flags.width && flags.zero && flags.isnum && flags.p && flags.minus)
		str = ft_set_minus_width(str, flags.width);
	else if (flags.width && flags.minus)
		str = ft_set_minus_width(str, flags.width);
	return (str);
}
