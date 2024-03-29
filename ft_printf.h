/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:24:54 by ztouzri           #+#    #+#             */
/*   Updated: 2021/03/14 18:27:18 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_pars {
	int		zero;
	int		minus;
	int		width;
	int		neg;
	int		null;
	int		precision;
	int		precision_on;
	char	convert;
	char	*str;
}				t_pars;

int				ft_printf(const char *format, ...);
t_pars			ft_parsinit(void);
int				ft_parser(const char *format, t_pars *pars, va_list args);
int				ft_translate(t_pars *pars);
int				width_handler(char *str, int width, int minus, int zero);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_minus_handler(t_pars *pars);
int				ft_nominus_handler(t_pars *pars);
int				strprecision_handler(char *str, int precision);
int				ft_atoi(const char *nptr);
char			*ft_itoa(int n);
char			*ft_utoa(unsigned int n);
int				ft_isdigit(int c);
char			*ft_itoa_base(long nbr, char *base);
char			*ft_ztoa_base(unsigned long long nbr, char *base);
int				ft_isin(char *str, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_putstr(char *str);
int				precision_handler(char *str, int precision);
int				ft_digitconvert(const char *format, t_pars *pars, int is_width);
int				ft_putchar(char c);
#endif
