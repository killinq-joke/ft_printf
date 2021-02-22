/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:33:31 by ztouzri           #+#    #+#             */
/*   Updated: 2021/02/22 14:28:14 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>

struct		s_pars {
	int zero;
	int minus;
	int precision;
	int width;
	int converter;
} typedef	t_pars ;

int		ft_printf(const char *format, ...);
void	*ft_parser(const char *format);
#endif
