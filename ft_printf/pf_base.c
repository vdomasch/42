/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:47:25 by vdomasch          #+#    #+#             */
/*   Updated: 2023/11/30 11:43:53 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_base(unsigned int n, char *base, unsigned int size, int *er)
{
	int		count;

	count = 0;
	if (n > (size - 1) && *er == 0)
		count += pf_base(n / size, base, size, er);
	n = n % size;
	pf_char(base[n], er);
	count++;
	return (count);
}
