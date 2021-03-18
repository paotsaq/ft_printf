/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 04:05:17 by apinto            #+#    #+#             */
/*   Updated: 2021/03/18 05:07:06 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// define enum with types?
// enum conv_type(c, s, p, d, i, u, x, X);
#define NBR_OF_TYPES 8
static const char types[NBR_OF_TYPES] = "cspdiuxX";
static const char legal_conv[NBR_OF_TYPES][6] = {{0, 1, 1, 0, 1, 1},
												  {0, 1, 1, 0, 1, 1},
												  {0, 1, 0, 0, 0, 1},
												  {1, 1, 1, 1, 1, 1},
												  {1, 1, 1, 1, 1, 1},
												  {1, 1, 1, 1, 1, 1},
												  {1, 1, 1, 1, 1, 1},
												  {1, 1, 1, 1, 1, 1}};
// legal_conv[conv_s][space] == true;
typedef struct	s_flags{
	int		zero;
	int		minus;
	int		width;
	int		prec;
	int		p_aster;
	int		w_aster;
	char	type;
	char*	CONVS[];
}				t_flags;

int				ft_printf(char *str, ...);
void			initializes_tr(t_flags *tr);
// make into a parser function?
void			retrieves_flags(t_flags *tr, char *str, int *i);
void			retrieves_prec(t_flags *tr, char *str, int *i, va_list *pargs);
void			retrieves_width(t_flags *tr, char *str, int *i, va_list *pargs);
void			retrieves_type(t_flags *tr, char *str, int *i, va_list *pargs);
void			parses_string(t_flags *tr, char *str, va_list *pargs);