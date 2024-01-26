/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:01:59 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/26 18:01:06 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	type_list(t_list list)
{
	if (list.len_a < 5)
		short_list(list);
	else
		long_list(list.list_a, list.list_b, list.len_a);
}

int	*long_list(int *list_a, int *list_b, int len_a)
{
	int	len_b;
	int	i;

	len_b = 0;
	push_b(&list_a, &list_b, len_a--, len_b++);
	push_b(&list_a, &list_b, len_a--, len_b++);
	while (len_a > 3)
		sort_number(&list_a, &list_b, len_a--, len_b++);
	list_b = lowest_at_bottom(list_b, len_b);
	list_of_three(list_a);
	while (len_b > 0)
		sort_number_a(&list_a, &list_b, len_a++, len_b--);
	return (list_a);
}

void	sort_number(int **list_a, int **list_b, int len_a, int len_b)
{
	int	index;

	index = len_a - 1;
	ready_b(*list_a, *list_b, index, len_b);
	push_b(list_a, list_b, len_a, len_b);
}

void	sort_number_a(int **list_a, int **list_b, int len_a, int len_b)
{
	int	index;

	index = len_b - 1;
	ready_a(*list_b, *list_a, index, len_a);
	push_a(list_b, list_a, len_b, len_a);
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
			while (i-- > 0)
				reverse_rotate_ab(list_b, len_b, 'b');
	}
	else if (i == -1)
		list_b = lowest_at_bottom(list_b, len_b);
	else if (i + 1 <= len_b / 2)
		while (i-- >= 0)
			reverse_rotate_ab(list_b, len_b, 'b');
	else
		while (++i <= len_b)
			rotate_ab(list_b, len_b, 'b');
}

void	ready_a(int *list_b, int *list_a, int index, int len_a)
{
	int	i;

	i = len_a - 1;
	while (list_b[index] > list_a[i] && i > 0)
		i--;
	if (i == -1)
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
