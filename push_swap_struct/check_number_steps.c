/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_steps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:38:49 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/29 14:25:58 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_less_steps_pb(int *list_a, int *list_b, int len_a, int len_b)
{
	int i;
	int	index;
	int	temp;
	int nb_steps;
	
	i = len_a;
	while (--i > 0)
	{
		temp = steps_list_a(list_a, len_a, i) + steps_list_b(list_b, len_b, list_a[i]) + 1;
		printf("i: %d list_a[i]: %d; temp:%d\n", i, list_a[i], temp);
		if (temp < nb_steps || i == len_a - 1)
		{
			nb_steps = temp;
			index = i;	
		}
	}
	return (index);
}

int	steps_list_a(int *list_a, int len_a, int index)
{
	if (list_a[index] + 1 < (len_a - 1) / 2)
		return (index);
	else
		return (len_a - index);
}

int	steps_list_b(int *list_b, int len_b, int value)
{
	int	i;
	
	i = len_b - 1;
	while (value < list_b[i] && i > 0)
		i--;
	if (i == len_b - 1)
	{
		i = 0;
		while (value > list_b[i] && i < len_b)
			i++;
		if (i == len_b)
			return (lowest_at_bottom_steps(list_b, len_b));
		else
			return (i);
	}
	else if (i == -1)
		return (lowest_at_bottom_steps(list_b, len_b));
	else if (i + 1 <= len_b / 2)
		return (i);
	else
		return (len_b - i);
}

int	lowest_at_bottom_steps(int *list, int len)
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
		return (0);
	if (location < len / 2)
		return (location + 1);
	else
		return ((len - location) * (-1));
}
