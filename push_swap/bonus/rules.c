/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:24:13 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/20 17:16:38 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_swap *list, char c)
{
	t_swap	*second;

	list = lstfirst_swap(list);
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	second = list->next;
	list->prev = second;
	if (second->next)
	{
		list->next = second->next;
		list->next->prev = list;
	}
	else
		list->next = NULL;
	second->next = list;
	second->prev = NULL;
}

/*void	swap_all(t_swap *a, t_swap *b)
{
	//if (a)
		swap(a, 0);
	//if (b)
		swap(b, 0);
	printf("ss\n");
}*/

t_swap	*push(t_swap *push, t_swap *pull, char c)
{
	t_swap	*save;

	save = push;
	if (push->next)
		save = push->next;
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
	return (save);
}

void	rotate(t_swap *list, char c)
{
	t_swap	*last;

	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	list = lstfirst_swap(list);
	last = lstlast_swap(list);
	last->next = list;
	list->next->prev = NULL;
	list->next = NULL;
	list->prev = last;
}

/*void	rotate_all(t_swap *a, t_swap *b)
{
	//if (a)
		rotate(a, 0);
	//if (b)
		rotate(b, 0);
	write(1, "rr\n", 3);
}*/

void	reverse_rotate(t_swap *list, char c)
{
	t_swap	*last;

	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	list = lstfirst_swap(list);
	last = lstlast_swap(list);
	list->prev = last;
	last->prev->next = NULL;
	last->next = list;
	last->prev = NULL;
}

/*void	reverse_rotate_all(t_swap *a, t_swap *b)
{
	if (a)
		reverse_rotate(a, 0);
	if (b)
		reverse_rotate(b, 0);
	write(1, "rrr\n", 4);
}*/

void	rule_all(t_swap *a, t_swap *b, char *str, bool print)
{
	if (ft_strncmp(str, "ss", 3) == 0)
	{
		swap(a, 0);
		swap(b, 0);
		if (print == 1)
			write(1, "ss\n", 3);
	}
	else if (ft_strncmp(str, "rr", 3) == 0)
	{
		rotate(a, 0);
		rotate(b, 0);
		if (print == 1)
			write(1, "rr\n", 3);
	}
	else if (ft_strncmp(str, "rrr", 4) == 0)
	{
		reverse_rotate(a, 0);
		reverse_rotate(b, 0);
		if (print == 1)
			write(1, "rrr\n", 4);
	}
}
