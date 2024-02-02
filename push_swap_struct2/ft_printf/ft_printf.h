/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:29:47 by vdomasch          #+#    #+#             */
/*   Updated: 2023/11/29 19:03:45 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int	pf_char(int c, int *er);
int	pf_str(char *str, int *er);
int	pf_ptr(unsigned long n, char *base, int *er);
int	pf_decimal(int n, int *er);
int	pf_base(unsigned int n, char *base, unsigned int size, int *er);
int	ft_printf(const char *str, ...);

#endif
