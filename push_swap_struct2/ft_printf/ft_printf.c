/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:55:11 by vdomasch          #+#    #+#             */
/*   Updated: 2023/12/05 13:49:02 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversions(const char *str, int i, va_list arg, int *er);

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	size_t		i;
	size_t		count;
	int			er;

	count = 0;
	er = 0;
	va_start(arg, str);
	i = 0;
	while (str[i] && er == 0)
	{
		if (str[i] == '%' && str[i++])
			count += conversions(str, i++, arg, &er);
		else
			count += pf_char(str[i++], &er);
	}
	va_end(arg);
	if (er != 0)
		return (-1);
	return (count);
}

static int	conversions(const char *str, int i, va_list arg, int *er)
{
	if (str[i] == 'c')
		return (pf_char(va_arg(arg, int), er));
	else if (str[i] == 's')
		return (pf_str(va_arg(arg, char *), er));
	else if (str[i] == 'p')
		return (pf_ptr(va_arg(arg, unsigned long), "0123456789abcdef", er));
	else if (str[i] == 'd' || str[i] == 'i')
		return (pf_decimal(va_arg(arg, int), er));
	else if (str[i] == 'u')
		return (pf_base(va_arg(arg, unsigned int), "0123456789", 10, er));
	else if (str[i] == 'x')
		return (pf_base(va_arg(arg, unsigned int), "0123456789abcdef", 16, er));
	else if (str[i] == 'X')
		return (pf_base(va_arg(arg, unsigned int), "0123456789ABCDEF", 16, er));
	else if (str[i] == '%')
		return (pf_char('%', er));
	else if (str[i] == '\0')
		*er = -1;
	return (0);
}
