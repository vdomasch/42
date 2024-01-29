/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:01:59 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/29 14:24:00 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	type_list(t_list list)
{
	if (list.len_a < 5)
		short_list(list);
	else
		long_list(list);
}

int	*long_list(t_list list)
{
	//int	len_b;
	int	i;

	list.len_b = 0;
	push_b(&list.list_a, &list.list_b, list.len_a--, list.len_b++);
	push_b(&list.list_a, &list.list_b, list.len_a--, list.len_b++);
	while (list.len_a > 9)
	{
		sort_number(&list);
		list.len_a--;
		list.len_b++;
	}
	//list.list_b = lowest_at_bottom(list.list_b, list.len_b);
	//list_of_three(list.list_a);
	//while (list.len_b > 0)
	//{
	//	sort_number_a(&list);
	//	list.len_a++;
	//	list.len_b--;
	//}
	return (list.list_a);
}

void	sort_number(t_list *list)
{
	int	index;
	
	index = list->len_a - 1;
	index = check_less_steps_pb(list->list_a, list->list_b, list->len_a, list->len_b);
	printf("index: %d; list_a[index]: %d\n", index, list->list_a[index]);
	while (index++ < list->len_a - 1)
		rotate_ab(list->list_a, list->len_a, 'a');
	//ready_b(list->list_a, list->list_b, index, list->len_b);
	push_b(&list->list_a, &list->list_b, list->len_a, list->len_b);
}

void	sort_number_a(t_list *list)
{
	int	index;

	index = list->len_b - 1;
	ready_a(list->list_b, list->list_a, index, list->len_a);
	push_a(&list->list_b, &list->list_a, list->len_b, list->len_a);
}

void	ready_b(int *list_a, int *list_b, int index, int len_b)
{
	int	i;

	i = len_b - 1;
	while (list_a[index] < list_b[i] && i > 0)
		i--;
	if (i == len_b - 1)
	{
		i = 0;
		while (list_a[index] > list_b[i] && i < len_b)
			i++;
		if (i == len_b)
			list_b = lowest_at_bottom(list_b, len_b);
		else
			while (i-- > -1)
				reverse_rotate_ab(list_b, len_b, 'b');
	}
	else if (i == 0)
		list_b = lowest_at_bottom(list_b, len_b);
	else if (i  + 1 <= len_b / 2)
		while (i-- >= 0)
			reverse_rotate_ab(list_b, len_b, 'b');
	else
		while (++i < len_b)
			rotate_ab(list_b, len_b, 'b');
}

void	ready_a(int *list_b, int *list_a, int index, int len_a)
{
	int	i;

	i = len_a - 1;
	while (list_b[index] > list_a[i] && i > 0)
		i--;
	if (i == 0)
	{
		list_a = lowest_at_top(list_a, len_a);
		return ;
	}
	if (i == len_a - 1)
	{
		i = 0;
		while (list_b[index] < list_a[i])
			i++;
		if (i == len_a)
			list_a = lowest_at_top(list_a, len_a);
		else
			while (i-- > 0)
				reverse_rotate_ab(list_a, len_a, 'a');
	}
	else
		while (i++ < len_a - 1)
			rotate_ab(list_a, len_a, 'a');
}

int	*lowest_at_bottom(int *list, int len)
{
	int	i;
	int	temp;
	int	location;

	i = 0;
	temp = list[i];
	location = i;
	while (++i < len)
	{
		if (list[i] < temp)
		{
			temp = list[i];
			location = i;
		}
	}
	if (location == 0)
		return (list);
	if (location < len / 2)
		while (location-- > 0)
			reverse_rotate_ab(list, len, 'b');
	else
		while (location++ < len)
			rotate_ab(list, len, 'b');
	return (list);
}

int	*lowest_at_top(int *list, int len)
{
	int	i;
	int	temp;
	int	location;

	i = 0;
	temp = list[i];
	location = i;
	while (++i < len)
	{
		if (list[i] < temp)
		{
			temp = list[i];
			location = i;
		}
	}
	if (location == len - 1)
		return (list);
	if (location > len / 2)
		while (location++ < len - 1)
			rotate_ab(list, len, 'b');
	else
		while (location-- >= 0)
			reverse_rotate_ab(list, len, 'b');
	return (list);
}

