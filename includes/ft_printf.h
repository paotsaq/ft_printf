/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 04:05:17 by apinto            #+#    #+#             */
/*   Updated: 2021/04/02 04:56:05 by apinto           ###   ########.fr       */
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
	// i am actually not sure negatives are implemented already
	int				negative;
	int				invalid;
}				t_info;

int				ft_printf(char *str, ...);
void			initializes_info(t_info *info);
void			handles_conversion(va_list *pargs, char *str, int *i);
void			*ft_reallocates_memory(void *old,
					size_t count, size_t size, int offset);
void			cleans_info_with_prios(t_info *info);
void			int_family_allocation(t_info *info, va_list *pargs, char *buffer);
void			char_family_allocation(t_info *info, va_list *pargs);
void			number_to_string(t_info *info, long long content, char *base, char *buffer);
void			writes_buffer(t_info *info);
