/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorythm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:22:31 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/08 18:15:08 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_number(t_swaplist *list_a, int argc)
{
	t_swaplist	*list_b;
	t_swaplist	*last;
	int			detain;
	int			count;
	int			chunk;
	int			num;
	int			rank_max;
	
	list_b = list_a;
	chunk = 0.000000053 * argc * argc + 0.03 * argc + 14.5;
	num = 0;
	rank_max = argc - 3;
	//printf("rank_max: %d\n", rank_max);
	while (argc > 3)
	{
		/*//printf("list_a->rank: %d ; num: %d\n",list_a->rank, num);
		if (list_a->rank <= num && list_a->rank < rank_max)
		{
			list_a = list_a->next;
			push(list_a->prev, list_b, 'b');
			if (list_b->prev)
				list_b = list_b->prev;
			num++;
		}
		else if (list_a->rank <= (num + chunk) && list_a->rank < rank_max)
		{
			list_a = list_a->next;
			push(list_a->prev, list_b, 'b');
			if (list_b->prev)			
				rotate(list_b->prev, 'b');
			num++;
		}
		else
		{
			//printf("v:%d||p:%p||c:%p||n:%p\n___\n", list_a->content, list_a->prev, list_a, list_a->next);
			list_a = list_a->next;
			//printf("v:%d||p:%p||c:%p||n:%p\n", list_a->content, list_a->prev, list_a, list_a->next);
			rotate(list_a->prev, 'a');
		}*/
		list_a = push_to_b(list_a, list_b, chunk, num);
		argc--;
	}
	while (list_a->prev)
		list_a = list_a->prev;
	sort_list_of_three(list_a);
	while (list_a->prev)
		list_a = list_a->prev;
	detain = 0;
	while (num > 0)
	{
		count = 0;
		last = lstlast_swap(list_a);
		if (detain)
		{
			last = list_b;
			while (last->next)
			{
				if (last->rank == list_a->rank - 1)
					break ;
				last = last->next;
				count++;
			}
			if (count < num * 0.5)
			{
				while (count--)
				{
					list_b = list_b->next;
					rotate(list_b->prev, 'b');
				}
				if (list_b->next)
				{
					list_b = list_b->next;
					push(list_b->prev, list_a, 'a');
				}
				push(list_b, list_a, 'a');
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
			last = lstlast_swap(list_a);
			if (last->rank == list_a->rank - 1)
			{
				reverse_rotate(list_a, 'a');
					list_a = list_a->prev;
				detain = 0;
			}
		}
		if (list_b->rank == list_a->rank - 1)
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
			detain = 1;
			num--;
		}
	}
}

t_swaplist	*push_to_b(t_swaplist *list_a, t_swaplist *list_b, int chunk, int rank_max)
{
	int	num;
	//printf("list_a->rank: %d ; num: %d\n",list_a->rank, num);
	while (list_a->prev)
		list_a = list_a->prev;
	num = 0;
	if (list_a->rank <= (num + chunk) && list_a->rank < rank_max)
	{
		list_a = list_a->next;
		push(list_a->prev, list_b, 'b');
		if (list_b->prev && list_a->rank <= num)
			rotate(list_a->prev, 'a');
		else if (list_b->prev)
			list_b = list_b->prev;
		num++;
	}
	else
	{
		//printf("v:%d||p:%p||c:%p||n:%p\n___\n", list_a->content, list_a->prev, list_a, list_a->next);
		list_a = list_a->next;
		//printf("v:%d||p:%p||c:%p||n:%p\n", list_a->content, list_a->prev, list_a, list_a->next);
	}
	return (list_a);
}

void	sort_list_of_three(t_swaplist *first)
{
	t_swaplist *second;
	t_swaplist *third;
	
	//printf("v:%d||p:%p||c:%p||n:%p\n\n", list->content, list->prev, list, list->next);
	second = first->next;
	third = first->next->next;
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
