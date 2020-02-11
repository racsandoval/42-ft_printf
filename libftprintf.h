/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsandova <rsandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:17:17 by rsandova          #+#    #+#             */
/*   Updated: 2020/02/11 17:19:53 by rsandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"
# define SYMBOLS "cspdiuxX%"
# define FLAGS "0123456789-.*"

typedef struct	s_flags
{
	int			width;
	int			p;
	int			zero;
	int			p_len;
	int			minus;
	int			isnum;
	int			ispointer;
	int			star_w;
	int			star_p;

}				t_flags;

int				ft_printf(const char *str, ...);
size_t			ft_is_str(char *str, t_flags flags);
size_t			ft_is_char(char c, t_flags flags);
size_t			ft_is_nbr(int n, t_flags flags);
size_t			ft_is_point(size_t num, t_flags flags);
char			*ft_ltoa_base(size_t n, char	*base, size_t b_len);
char			*ft_u_itoa(unsigned int nbr);
char			*ft_itoa_hex(unsigned int n);
size_t			ft_is_uint(unsigned int n, t_flags flags);
size_t			ft_is_hex(unsigned int n, char c, t_flags flags);
void			ft_str_toupper(char *str);
size_t			ft_is_percent(char c, t_flags flags);
t_flags			ft_flag_width(const char *format, t_flags flags);
char			*ft_set_flags(char *str, t_flags flags);
t_flags			ft_flag_point_len(const char *format, t_flags flags);
char			*ft_set_point_str(char *str, int point);
char			*ft_set_point_num(char *str, int point);
char			*ft_set_point_pointer(char	*str, int point);
t_flags			ft_check_star(t_flags flags, va_list ap);
char			*ft_set_null_point(char	*str);

#endif
