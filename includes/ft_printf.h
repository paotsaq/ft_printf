/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 04:05:17 by apinto            #+#    #+#             */
/*   Updated: 2021/03/29 11:27:54 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../libft/libft.h"

#define TYPES "cspdiuxX"
#define DEC_BASE "0123456789"
#define HEX_BASE "0123456789abcdef"

typedef struct	s_info{
	int				zero;
	int				minus;
	int				width;
	int				prec;
	int				w_inp;
	int				p_inp;
	int				w_aster;
	int				p_aster;
	char			type;
	void			*content;
	int				len;
	int				size;
	// for numbers only!
	int				negative;
	int				invalid;
}				t_info;

int				ft_printf(char *str, ...);
void			initializes_tr(t_info *tr);
void			parses_string(t_info *tr, char *str, va_list *pargs);
void			*ft_reallocates_memory(void *old,
					size_t count, size_t size, int offset);
char			*creates_buffer(t_info *info);
void			cleans_info_with_prios(t_info *tr);
void			int_family_allocation(t_info *tr, va_list *pargs);
char			*tests_buffer(char *str, ...);
void			char_family_allocation(t_info *tr, va_list *pargs);
void			number_to_string(t_info *tr, unsigned int content, char *base);
