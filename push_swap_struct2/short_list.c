/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:47:23 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/02 10:24:14 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	short_list(t_list a, t_list b)
{
	if (a.len == 2)
		list_of_two(a.list);
	else if (a.len == 3)
		list_of_three(a.list);
	else
		list_of_four(a.list, b.list);
}

void	list_of_two(int *list)
{
	if (list[1] < list[0])
		return ;
	swap_ab(list, 2, 'a');
}

void	list_of_three(int *list)
{
	if (list[2] < list[1] && list[1] < list[0])
		return ;
	else if ((list[2] < list[1] && list[2] < list[0] && list[1] > list[0])
		|| (list[2] < list[1] && list[2] > list[0] && list[1] > list[0]))
		reverse_rotate_ab(list, 3, 'a');
	else if (list[2] > list[1] && list[2] > list[0])
		rotate_ab(list, 3, 'a');
	if (list[2] > list[1] && list[2] < list[0] && list[1] < list[0])
		swap_ab(list, 3, 'a');
}

void	list_of_four(t_list list)
{
	int	i;
	int	temp;
	int	location;

	i = 1;
	temp = list.list_a[0];
	while (i < 4)
	{
		if (list.list_a[i] < temp)
		{
			temp = list.list_a[i];
			location = i;
		}
		i++;
	}
	if (location == 0)
		reverse_rotate_ab(list.list_a, list.len_a, 'a');
	else if (location == 1)
		rotate_ab(list.list_a, list.len_a, 'a');
	if (location == 2 || location == 1)
		swap_ab(list.list_a, list.len_a, 'a');
	push_b(&list.list_a, &list.list_b, list.len_a, list.len_b);
	list_of_three(list.list_a);
	push_a(&list.list_b, &list.list_a, 1, 3);
}*/
