/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:45:53 by vdomasch          #+#    #+#             */
/*   Updated: 2023/11/30 18:19:09 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
