/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:28:38 by rsandova          #+#    #+#             */
/*   Updated: 2020/02/11 16:58:27 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <stdio.h>

char	*make_null(void)
{
	char	*str;

	str = ft_strdup("(null)");
	return (str);
}

size_t	ft_is_str(char *str, t_flags flags)
{
	char	*new_str;
	size_t	len;

	if (!str)
	{
		new_str = make_null();
	}
	else
	{
		new_str = malloc(ft_strlen(str));
		ft_strlcpy(new_str, str, ft_strlen(str) + 1);
	}
	new_str = ft_set_flags(new_str, flags);
	len = ft_strlen(new_str);
	ft_putstr(new_str);
	free(new_str);
	return (len);
}

size_t	null_char(char *str, t_flags flags, size_t len)
{
	size_t	count;

	if (!len)
	{
		ft_putchar_fd(0, 1);
		return (1);
	}
	if (flags.minus)
	{
		ft_putchar_fd(0, 1);
		ft_putstr(&str[1]);
		return (len);
	}
	count = 0;
	while (count < len - 1)
		ft_putchar_fd(str[count++], 1);
	ft_putchar_fd(0, 1);
	return (len);
}

size_t	ft_is_char(char c, t_flags flags)
{
	char	*str;
	size_t	len;

	str = malloc(2);
	str[0] = c;
	str[1] = '\0';
	str = ft_set_flags(str, flags);
	len = ft_strlen(str);
	if (!c)
	{
		len = null_char(str, flags, len);
		return (len);
	}
	ft_putstr(str);
	free(str);
	return (len);
}

size_t	ft_is_percent(char c, t_flags flags)
{
	char	*str;
	size_t	len;

	str = (char *)malloc(2);
	str[0] = c;
	str[1] = '\0';
	str = ft_set_flags(str, flags);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
