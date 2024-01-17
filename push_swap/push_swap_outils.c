/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:24:13 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/17 14:29:26 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*_sasb(int *list, int len)
{
	int	temp;

	temp = list[len - 1];
	list[len - 1] = list[len - 2];
	list[len - 2] = temp;
	return (list);
}
void _ss(int **list_a, int **list_b, int len)
{
	*list_a = _sasb(*list_a, len);
	*list_b = _sasb(*list_b, len);
}