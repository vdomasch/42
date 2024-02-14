/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:24:13 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/07 14:36:36 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_swaplist *stack, char c)
{
	t_swaplist	*stack2;

	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	stack2 = stack->next;
	stack->prev = stack2;
	stack->next = stack2->next;
	stack2->next = stack;
	stack->next->prev = stack;
	stack2->prev = NULL;
}

/*void	swap_all(t_swaplist *a, t_swaplist *b)
{
	//if (a)
		swap(a, 0);
	//if (b)
		swap(b, 0);
	printf("ss\n");
}*/

void	push(t_swaplist *push, t_swaplist *pull, char c)
{
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
	if (push->next)
		push->next->prev = NULL;
	if (push != pull)
	{
		pull->prev = push;
		push->next = pull;
	}
	else
		push->next = NULL;
	//printf("||%d %d||", pull->content, pull->prev->content);
}

void	rotate(t_swaplist *stack, char c)
{
	t_swaplist	*last;

	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	last = lstlast_swap(stack);
	last->next = stack;
	stack->next->prev = NULL;
	stack->next = NULL;
	stack->prev = last;
}

/*void	rotate_all(t_swaplist *a, t_swaplist *b)
{
	//if (a)
		rotate(a, 0);
	//if (b)
		rotate(b, 0);
	write(1, "rr\n", 3);
}*/

void	reverse_rotate(t_swaplist *stack, char c)
{
	t_swaplist	*last;

	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	last = lstlast_swap(stack);
	stack->prev = last;
	last->prev->next = NULL;
	last->next = stack;
	last->prev = NULL;
}

/*void	reverse_rotate_all(t_swaplist *a, t_swaplist *b)
{
	if (a)
		reverse_rotate(a, 0);
	if (b)
		reverse_rotate(b, 0);
	write(1, "rrr\n", 4);
}*/

void	rule_all(t_swaplist *a, t_swaplist *b, char *str)
{
	if (strncmp(str, "ss", 3) == 0)
	{
		//if (a)
		swap(a, 0);
		//if (b)
		swap(b, 0);
		printf("ss\n");
	}
	else if (strncmp(str, "rr", 3) == 0)
	{
		//if (a)
		rotate(a, 0);
		//if (b)
		rotate(b, 0);
		write(1, "rr\n", 3);
	}
	else if (strncmp(str, "rrr", 4) == 0)
	{
		//if (a)
		reverse_rotate(a, 0);
		//if (b)
		reverse_rotate(b, 0);
		write(1, "rrr\n", 4);
	}
}
