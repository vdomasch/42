/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:46:52 by vdomasch          #+#    #+#             */
/*   Updated: 2023/11/30 11:44:03 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_decimal(int n, int *er)
{
	int	sign;
	int	count;

	count = 0;
	sign = 1;
	if (n < 0)
	{
		if (n > -10)
			count += pf_char('-', er);
		sign = -1;
	}
	if ((n > 9 || n < -9) && *er == 0)
		count += pf_decimal(n / 10, er);
	n = n % 10 * sign + 48;
	pf_char(n, er);
	count++;
	return (count);
}
