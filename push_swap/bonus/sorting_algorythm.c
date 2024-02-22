/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorythm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:22:31 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/22 11:15:46 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/****************************************************************************/
/*									PUSH TO A								*/
/****************************************************************************/

t_swap	*push_to_a(t_swap *list_a, t_swap *list_b, const int num)
{
	static int	detain = 0;

	while (list_b->prev)
		list_b = list_b->prev;
	while (list_a->prev)
		list_a = list_a->prev;
	if (detain)
	{
		list_b = detain_number(list_a, list_b, num, &detain);
	}
	else if (list_b->rank == list_a->rank - 1)
	{
		list_b = push(list_b, list_a, 'a');
	}
	else
	{
		list_b = push(list_b, list_a, 'a');
		rotate(list_a->prev, 'a');
		detain = 1;
	}
	return (list_b);
}

/****************************************************************************/
/*									PUSH TO B								*/
/****************************************************************************/

void	push_to_b(t_swap *list_a, t_swap *list_b, int argc, int *num)
{
	const int	rank_max = argc - 3;
	const int	chunk = 0.000000053 * argc * argc + 0.03 * argc + 14.5;

	if (list_a->rank <= *num && list_a->rank < rank_max)
	{
		push(list_a, list_b, 'b');
		if (list_b->prev)
			list_b = list_b->prev;
		*num += 1;
	}
	else if (list_a->rank <= (*num + chunk) && list_a->rank < rank_max)
	{
		push(list_a, list_b, 'b');
		if (list_b->prev)
			rotate(list_b->prev, 'b');
		*num += 1;
	}
	else
		rotate(list_a, 'a');
}

/****************************************************************************/
/*								SORTING ALGORYTHM							*/
/****************************************************************************/

void	sort_number(t_swap *list_a, int argc, int num)
{
	t_swap	*list_b;

	if (argc == 2)
		return (sort_list_of_two(list_a));
	if (check_sorted(list_a, argc))
		return ;
	while (argc - num > 3)
	{
		if (num == 0)
			list_b = list_a;
		list_a = list_a->next;
		push_to_b(list_a->prev, list_b, argc, &num);
		if (list_b->prev)
			list_b = list_b->prev;
	}
	sort_list_of_three(list_a);
	while (num-- > 0)
	{
		list_b = push_to_a(list_a, list_b, num + 1);
	}
}

/****************************************************************************/
/*									SORT SHORT								*/
/****************************************************************************/

void	sort_list_of_two(t_swap *list)
{
	if (list->next->rank != list->rank + 1)
		swap(list, 'a');
}

void	sort_list_of_three(t_swap *l1)
{
	t_swap	*l2;
	t_swap	*l3;

	l2 = l1->next;
	l3 = l1->next->next;
	if ((l1->rank < l2->rank && l1->rank < l3->rank && l2->rank > l3->rank)
		|| (l1->rank < l2->rank && l1->rank > l3->rank && l2->rank > l3->rank))
	{
		reverse_rotate(l1, 'a');
		l1 = l1->prev;
		l2 = l1->next;
		l3 = l2->next;
	}
	else if (l1->rank > l2->rank && l1->rank > l3->rank)
	{
		rotate(l1, 'a');
		l1 = l2;
		l2 = l3;
		l3 = l3->next;
	}
	if (l1->rank > l2->rank && l1->rank < l3->rank && l2->rank < l3->rank)
		swap(l1, 'a');
}
