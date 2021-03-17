/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 04:05:17 by apinto            #+#    #+#             */
/*   Updated: 2021/03/17 07:48:29 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "libft.h"

// define enum with types?
#define TYPES "spdiuxX"
#define FLAGS "0-*."
#define  "0-*."

// define as array?
typedef struct	s_flags{
	int		zero;
	int		minus;
	int		width;
	int		p_aster;
	int		prec;
	int		w_aster;
	int		invalid;
}				t_flags;

void			initializes_tr(t_flags *tr);
void			checks_flags(t_flags *tr, char *str, int *i);
void			checks_prec(t_flags *tr, char *str, int *i, va_list *pargs);
void			checks_width(t_flags *tr, char *str, int *i, va_list *pargs);
void			checks_type(t_flags *tr, char *str, int *i, va_list *pargs);
