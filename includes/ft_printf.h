/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 04:05:17 by apinto            #+#    #+#             */
/*   Updated: 2021/03/21 13:38:39 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#define TYPES "cspdiuxX"
#define DEC_BASE "0123456789"
#define HEX_BASE "0123456789abcdef"

// 0, -, w, p existem sempre...
//	     		   zmwppwp
//# define C_FLAGS 0b0111011
//# define S_FLAGS 0b0111111
//# define P_FLAGS 0b0101001
//# define D_FLAGS 0b1111011
//# define I_FLAGS 0b1111011
//# define U_FLAGS 0b1111011
//# define X_FLAGS 0b1111011

//	     		   zp
//# define C_FLAGS 0b00
//# define S_FLAGS 0b01
//# define P_FLAGS 0b00
//# define D_FLAGS 0b10
//# define I_FLAGS 0b10
//# define U_FLAGS 0b10
//# define X_FLAGS 0b10

// struct content is not bits because
typedef struct	s_info{
	int				zero;
	int				minus;
	int				width;
	int				prec;
	int				w_aster;
	int				p_aster;
	char			type;
	void			*content;
	int				len;
	// for numbers only!
	int				base;
	int				negative;
	int				invalid;
}				t_info;

int				ft_printf(char *str, ...);
void			initializes_tr(t_info *tr);
void			parses_string(t_info *tr, char *str, va_list *pargs);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
void			*ft_calloc(size_t count, size_t size);
void			*ft_reallocates_memory(void *old,
					size_t count, size_t size, int offset);
char			*creates_buffer(t_info *info);
void			cleans_info_with_prios(t_info *tr);
int				min(int args, int init, ...);
int				max(int args, int init, ...);
