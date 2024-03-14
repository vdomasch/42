/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:24:13 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/14 08:45:23 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_swap *list, char c, int *error)
{
	t_swap	*second;

	list = lstfirst_swap(list);
	if (c == 'a')
	{
		if (write(1, "sa\n", 3) == -1)
			*error = 1;
	}
	else if (c == 'b')
		if (write(1, "sb\n", 3) == -1)
			*error = 1;
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

t_swap	*push(t_swap *push, t_swap *pull, char c, int *error)
{
	t_swap	*save;

	save = push;
	if (push->next)
		save = push->next;
	if (c == 'a')
	{
		if (write(1, "pa\n", 3) == -1)
			*error = 1;
	}
	else if (c == 'b')
		if (write(1, "pb\n", 3) == -1)
			*error = 1;
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

void	rotate(t_swap *list, char c, int *error)
{
	t_swap	*last;

	if (c == 'a')
	{
		if (write(1, "ra\n", 3) == -1)
			*error = 1;
	}
	else if (c == 'b')
		if (write(1, "rb\n", 3) == -1)
			*error = 1;
	list = lstfirst_swap(list);
	last = lstlast_swap(list);
	last->next = list;
	list->next->prev = NULL;
	list->next = NULL;
	list->prev = last;
}

void	reverse_rotate(t_swap *list, char c, int *error)
{
	t_swap	*last;

	if (c == 'a')
	{
		if (write(1, "rra\n", 4) == -1)
			*error = 1;
	}
	else if (c == 'b')
		if (write(1, "rrb\n", 4) == -1)
			*error = 1;
	list = lstfirst_swap(list);
	last = lstlast_swap(list);
	list->prev = last;
	last->prev->next = NULL;
	last->next = list;
	last->prev = NULL;
}

void	rule_all(t_swap *a, t_swap *b, char *str, int *error)
{
	if (ft_strncmp(str, "ss", 3) == 0)
	{
		if (a)
			swap(a, 0, error);
		if (b)
			swap(b, 0, error);
	}
	else if (ft_strncmp(str, "rr", 3) == 0)
	{
		if (a)
			rotate(a, 0, error);
		if (b)
			rotate(b, 0, error);
	}
	else if (ft_strncmp(str, "rrr", 4) == 0)
	{
		if (a)
			reverse_rotate(a, 0, error);
		if (b)
			reverse_rotate(b, 0, error);
	}
	if (write(1, str, ft_strlen(str)) == -1)
		*error = 1;
}
