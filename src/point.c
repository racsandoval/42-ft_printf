/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:34:45 by rsandova          #+#    #+#             */
/*   Updated: 2020/02/11 17:03:27 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

char	*ft_set_point_num(char *str, int point)
{
	char	*new_str;
	int		len;
	int		minus;

	if ((str[0] != '-' && point <= (int)ft_strlen(str) && point)
		|| (str[0] == '-' && point <= (int)ft_strlen(str) - 1 && point))
		return (str);
	minus = (str[0] == '-') ? 1 : 0;
	new_str = (char *)malloc(point + 1 + minus);
	len = (int)ft_strlen(str) - 1;
	new_str[point-- + minus] = 0;
	while (len >= minus && point > 0)
		new_str[minus + point--] = str[len--];
	while ((int)point - minus + 1 >= 0)
		new_str[minus + point--] = '0';
	if (minus)
		new_str[0] = '-';
	free(str);
	return (new_str);
}

char	*ft_set_point_pointer(char *str, int point)
{
	char	*new_str;
	int		len;

	if (point <= (int)ft_strlen(str) - 2 && point)
		return (str);
	new_str = (char *)malloc(point + 3);
	len = (int)ft_strlen(str) - 1;
	new_str[point-- + 2] = 0;
	while (len > 1 && point > 0)
		new_str[point-- + 2] = str[len--];
	while (point >= 0)
		new_str[point-- + 2] = '0';
	new_str[1] = 'x';
	new_str[0] = '0';
	free(str);
	return (new_str);
}

char	*ft_set_point_str(char *str, int point)
{
	char	*new_str;
	int		len;

	if (point >= (int)ft_strlen(str))
		return (str);
	new_str = (char	*)malloc(point + 1);
	len = 0;
	while (len < (int)point)
	{
		new_str[len] = str[len];
		len++;
	}
	new_str[len] = '\0';
	free(str);
	return (new_str);
}

char	*ft_set_null_point(char *str)
{
	char	*new_str;

	if (str[0] == '0' && ft_strlen(str) == 1)
	{
		new_str = (char *)malloc(1);
		new_str[0] = '\0';
		return (new_str);
	}
	return (str);
}
