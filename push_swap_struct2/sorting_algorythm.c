/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorythm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:22:31 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/06 15:13:26 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_number(t_swaplist *list_a, int argc)
{
	t_swaplist *list_b;
	int	chunk;
	int	num;
	
	list_b = list_a;
	chunk = 0.000000053 * argc * argc + 0.03 * argc + 14.5;
	num = 0;
	while (argc > 3)
	{
		if (list_a->rank <= num)
		{
			list_a = list_a->next;
			push(list_a->prev, list_b, 'b');
			if (list_b->prev)
				list_b = list_b->prev;
			num++;
		}
		else if (list_a->rank <= (num + chunk))
		{
			list_a = list_a->next;
			push(list_a->prev, list_b, 'b');
			if (list_b->prev)			
				rotate(list_b->prev, 'b');
			num++;
		}
		else
			list_a = list_a->next;
			rotate(list_a->prev, 'a');
	}
}
