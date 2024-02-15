/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorythm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:22:31 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/15 18:52:27 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_position(t_swaplist *list, int rank, int num)
{
	int	count;
	
	count = 0;
	while (list->rank != rank - 1)
	{
		list = list->next;
		count++;
	}
	if (count < num * 0.5)
		return (count);
	else
		return (count * (-1));
}

int	detain_number(t_swaplist *list_a, t_swaplist *list_b, int num)
{
	t_swaplist	*last;
	int			count;
	
	count = 0;
	last = lstlast_swap(list_a);
	count = count_position(list_b, list_a->rank, num);
	while (count-- > 0)
	{
		list_b = list_b->next;
		rotate(list_b->prev, 'b');
	}
	while (count++ < 0)
	{
		reverse_rotate(list_b, 'b');
		list_b = list_b->prev;
	printf("count:%d\n", count);
	}
	push(list_b, list_a, 'a');
	if (last->rank == list_a->prev->rank - 1)
	{
		reverse_rotate(list_a->prev, 'a');
		return (0);
	}
	return (1);
}

void	push_to_b(t_swaplist *list_a, t_swaplist *list_b, int argc, int *num)
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

void	push_back_to_a(t_swaplist *list_a, t_swaplist *list_b, const int num)
{
	t_swaplist	*last;
	static int	detain;
	
	last = lstlast_swap(list_a);
	if (detain)
	{
		if (list_b->rank == list_a->rank - 1)
		{
			list_b = list_b->next;
			detain = detain_number(list_a, list_b->prev, num);
		}
		else
			detain = detain_number(list_a, list_b, num);
		while (list_a->prev)
			list_a = list_a->prev;
	}
	if (list_b->rank == list_a->rank - 1)
		push(list_b, list_a, 'a');
	else if (list_b->rank < last->rank)
	{
		printf("num: %d\n", num);
		push(list_b, list_a, 'a');
		rotate(list_a->prev, 'a');
		detain = 1;
	}
}

void	sort_number(t_swaplist *list_a, int argc, int num)
{
	t_swaplist	*list_b;
	
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
	while (list_a->prev)
		list_a = list_a->prev;
	printf("push to a\n");
	while (num-- > 0)
	{
		if (list_b->next)
		{
			list_b = list_b->next;
			push_back_to_a(list_a, list_b->prev, num + 1);
		}
		else
			push_back_to_a(list_a, list_b, num + 1);
		if (list_a->prev)
			list_a = list_a->prev;
	}
}


/*void	sort_number(t_swaplist *list_a, int argc)
{
	t_swaplist	*list_b;
	t_swaplist	*last;
	int			detain;
	int			count;
	int			chunk;
	int			num;
	int			nb_elements;
	int			rank_max;
	
	list_b = list_a;
	chunk = 0.000000053 * argc * argc + 0.03 * argc + 14.5;
	num = 0;
	nb_elements = argc;
	rank_max = argc - 3;
	//printf("rank_max: %d\n", rank_max);
	while (nb_elements > 3)
	{
		//printf("list_a->rank: %d ; num: %d\n",list_a->rank, num);
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
		}
		nb_elements--;
	}
	printf("here\n");
	while (list_a->prev)
		list_a = list_a->prev;
	while (list_b->prev)
		list_b = list_b->prev;
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
}*/


void	sort_list_of_three(t_swaplist *first)
{
	t_swaplist *second;
	t_swaplist *third;
	
	//printf("v:%d||p:%p||c:%p||n:%p\n\n", list->content, list->prev, list, list->next);
	second = first->next;
	third = first->next->next;
	if ((first->rank < second->rank && first->rank < third->rank && second->rank > third->rank)
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
