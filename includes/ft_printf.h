/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 04:05:17 by apinto            #+#    #+#             */
/*   Updated: 2021/03/19 05:47:28 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

// define enum with types?
// enum conv_type(c, s, p, d, i, u, x, X);
#define NBR_OF_TYPES 8
static const char types[NBR_OF_TYPES] = "cspdiuxX";
// usar prios apenas na recolha da info?
// nao, estupido, porque o tipo e a ultima informacao a recolher.
// usar prios para FILTRAR info? 💫

// os params que forem invalidos, multiplicam pela flag 0
// antes de chegarem a impressao; a variavel passa para dentro
// de uma func intermedia.
										   // z  m  w  p  p  w  p
static const char prios[NBR_OF_TYPES][7] = { {0, 1, 1, 0, 0, 1, 1},
											 {0, 1, 1, 1, 1, 1, 1},
											 {0, 1, 0, 0, 0, 0, 1},
											 {1, 1, 1, 0, 0, 1, 1},
											 {1, 1, 1, 0, 0, 1, 1},
											 {1, 1, 1, 0, 0, 1, 1},
											 {1, 1, 1, 0, 0, 1, 1},
											 {1, 1, 1, 0, 0, 1, 1}};
// legal_conv[conv_s][space] == true;
typedef struct	s_flags{
	int				zero;
	int				minus;
	int				width; //
	int				prec;  //
	int				prec_trim;
	int				w_aster;
	int				p_aster;
	char			type;
	// last added for print
	unsigned char	*content;
	int				len;  //
}				t_info;

int				ft_printf(char *str, ...);
void			initializes_tr(t_info *tr);
void			retrieves_flags(t_info *tr, char *str, int *i);
void			retrieves_prec(t_info *tr, char *str, int *i, va_list *pargs);
void			retrieves_width(t_info *tr, char *str, int *i, va_list *pargs);
void			retrieves_type(t_info *tr, char *str, int *i, va_list *pargs);
void			parses_string(t_info *tr, char *str, va_list *pargs);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
void			*ft_calloc(size_t count, size_t size);
//
int				min(int args, int init, ...);
int				max(int args, int init, ...);
