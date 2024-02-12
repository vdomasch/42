/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:28:39 by vdomasch          #+#    #+#             */
/*   Updated: 2023/11/17 18:03:30 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long int	number;
	long int	number_cmp;
	size_t		i;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number_cmp = (number * 10) + (str[i++] - 48);
		if (number > number_cmp && sign > 0)
			return (-1);
		if (number > number_cmp && sign < 0)
			return (0);
		number = number_cmp;
	}
	return (number * sign);
}
