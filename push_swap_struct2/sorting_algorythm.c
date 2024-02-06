/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorythm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:22:31 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/06 17:27:34 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_number(t_swaplist *list_a, int argc)
{
	t_swaplist	*list_b;
	t_swaplist	*last;
	int			chunk;
	int			num;
	int			count;
	
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
		{
			printf("v:%d||p:%p||c:%p||n:%p\n___\n", list_a->content, list_a->prev, list_a, list_a->next);
			list_a = list_a->next;
			printf("v:%d||p:%p||c:%p||n:%p\n", list_a->content, list_a->prev, list_a, list_a->next);
			rotate(list_a->prev, 'a');
		}
		argc--;
	}
	while (list_a->prev)
		list_a = list_a->prev;
	sort_list_of_three(list_a);
	while (list_a->prev)
		list_a = list_a->prev;
	while (num > 0)
	{
		count = 1;
		last = lstlast_swap(list_a);
		if (list_b->rank == list_a->rank + 1)
		{
			list_b = list_b->next;
			push(list_b->prev, list_a, 'a');
			list_a = list_a->prev;
			num--;
		}
		else if (list_b->rank < last->rank)
		{
			list_b = list_b->next;
			push(list_b->prev, list_a, 'a');
			rotate(list_a->prev, 'a');
			num--;
		}
		else 
		{
			last = list_b;
			while (last->next)
				if (last->rank == list_a->rank - 1)
					break ;
			count++;
			if (count < num * 0.5)
			{
				while (count--)
				{
					list_b = list_b->next;
					rotate(list_b->prev, 'b');
				}
				list_b = list_b->next;
				push(list_b->prev, list_a, 'a');
				list_a = list_a->prev;
				num--;
			}
			else
			{
				while (count++ < num)
				{
					reverse_rotate(list_b, 'b');
					list_b = list_b->prev;
				}
				list_b = list_b->next;
				push(list_b->prev, list_a, 'a');
				list_a = list_a->prev;
				num--;
			}
		}
	}
}

void	sort_list_of_three(t_swaplist *list)
{
	printf("v:%d||p:%p||c:%p||n:%p\n\n", list->content, list->prev, list, list->next);
	if (list->next->next->rank < list->next->rank && list->next->rank < list->rank)
		return ;
	else if ((list->next->next->rank < list->next->rank && list->next->next->rank < list->rank && list->next->rank > list->rank)
		|| (list->next->next->rank < list->next->rank && list->next->next->rank > list->rank && list->next->rank > list->rank))
		reverse_rotate(list, 'a');
	else if (list->next->next->rank > list->next->rank && list->next->next->rank > list->rank)
		rotate(list, 'a');
	if (list->next->next->rank > list->next->rank && list->next->next->rank < list->rank && list->next->rank < list->rank)
		swap(list, 'a');
}
