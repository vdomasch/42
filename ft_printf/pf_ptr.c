/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:46:25 by vdomasch          #+#    #+#             */
/*   Updated: 2023/11/30 11:44:10 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_ptr(unsigned long n, char *base, int *er)
{
	int	count;

	count = 0;
	if (!n)
		count += pf_str("(nil)", er);
	else
	{
		if (n < 16)
			count += pf_str("0x", er);
		if (n > 15 && *er == 0)
			count += pf_ptr(n / 16, base, er);
		n = n % 16;
		pf_char(base[n], er);
		count++;
	}
	return (count);
}
