/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:47:25 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/14 16:54:51 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	pf_char(int c, int *er)
{
	if (write(1, &c, 1) == -1)
		*er = -1;
	return (1);
}

int	pf_str(char *str, int *er)
{
	int	i;

	if (str == NULL)
		return (pf_str("(null)", er));
	i = 0;
	while (str[i])
		i++;
	if (write(1, str, i) == -1)
		*er = -1;
	return (i);
}

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
