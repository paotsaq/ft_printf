/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 04:05:17 by apinto            #+#    #+#             */
/*   Updated: 2021/03/17 17:56:10 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// define enum with types?
static const char types[9] = "cspdiuxX";
static const char legal_conv[7][6] = {{0, 1, 1, 0, 1, 1},
									  {0, 1, 1, 0, 1, 1},
									  {0, 1, 0, 0, 0, 1},
									  {1, 1, 1, 1, 1, 1},
									  {1, 1, 1, 1, 1, 1},
									  {1, 1, 1, 1, 1, 1},
									  {1, 1, 1, 1, 1, 1},
									  {1, 1, 1, 1, 1, 1}};
// legal_conv[conv_s][space] == true;
typedef struct	s_flags{
	// ignorar o invalid;
	int		invalid;
	int		zero;
	int		minus;
	int		width;
	int		prec;
	int		p_aster;
	int		w_aster;
	char	type;
	char*	CONVS[];
}				t_flags;

void			initializes_tr(t_flags *tr);
void			checks_flags(t_flags *tr, char *str, int *i);
void			checks_prec(t_flags *tr, char *str, int *i, va_list *pargs);
void			checks_width(t_flags *tr, char *str, int *i, va_list *pargs);
void			checks_type(t_flags *tr, char *str, int *i, va_list *pargs);
void			checks_validity(t_flags *tr, char *str, int *i);
