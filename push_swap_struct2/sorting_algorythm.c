/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorythm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:22:31 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/06 17:52:29 by vdomasch         ###   ########.fr       */
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
	printf("here\n");
	while (num > 0)
	{
		count = 1;
		last = lstlast_swap(list_a);
		if (list_b->rank == list_a->rank + 1)
		{
			if (list_b->next)
			{
				list_b = list_b->next;
				push(list_b->prev, list_a, 'a');
			}
			else
				push(list_b, list_a, 'a');
			list_a = list_a->prev;
			num--;
		}
		else if (list_b->rank < last->rank)
		{
			if (list_b->next)
			{
				list_b = list_b->next;
				push(list_b->prev, list_a, 'a');
			}
			else
				push(list_b, list_a, 'a');
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
	t_swaplist *first;
	t_swaplist *second;
	t_swaplist *third;
	
	printf("v:%d||p:%p||c:%p||n:%p\n\n", list->content, list->prev, list, list->next);
	first = list;
	second = list->next;
	third = list->next->next;
	if (first->rank < second->rank && second->rank < third->rank)
		return ;
	else if ((first->rank < second->rank && first->rank < third->rank && second->rank > third->rank)
		|| (first->rank < second->rank && first->rank > third->rank && second->rank > third->rank))
		{
			reverse_rotate(first, 'a');
			first = first->prev;
			second = first->next;
			third = second->next;
		}
	else if (first->rank > second->rank && first->rank > third->rank)
		{
			rotate(first, 'a');
			first = second;
			second = third;
			third = third->next;
		}
	if (first->rank > second->rank && first->rank < third->rank && second->rank < third->rank)
		swap(first, 'a');
}
