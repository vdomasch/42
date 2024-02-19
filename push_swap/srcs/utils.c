/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:01:10 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/19 20:03:53 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rank_list(t_swap *list, int argc)
{
	t_swap	*min_unrank;
	t_swap	*start;
	int		temp;
	int		i;

	i = -1;
	start = list;
	while (++i < argc)
	{
		temp = INT_MAX;
		while (list)
		{
			if (list->content < temp && list->rank == -1)
			{
				temp = list->content;
				min_unrank = list;
			}
			list = list->next;
		}
		min_unrank->rank = i;
		list = start;
	}
}

t_swap	*detain_number(t_swap *list_a, t_swap *list_b, int num, int *detain)
{
	t_swap	*last;
	int		count;

	count = 0;
	last = lstlast_swap(list_a);
	count = count_position(list_b, list_a->rank, num);
	if (count > 0)
		while (count-- > 0)
			rotate(list_b, 'b');
	else
		while (count++ < 0)
			reverse_rotate(list_b, 'b');
	list_b = lstfirst_swap(list_b);
	list_b = push(list_b, list_a, 'a');
	if (last->rank == list_a->prev->rank - 1)
	{
		reverse_rotate(list_a->prev, 'a');
		*detain = 0;
	}
	return (list_b);
}

int	count_position(t_swap *list, int rank, int num)
{
	int	count;

	count = 0;
	list = lstfirst_swap(list);
	while (list->rank != rank - 1)
	{
		list = list->next;
		count++;
	}
	if (count < num * 0.5)
		return (count);
	else
		return (count - num);
}

bool	ft_isspace(int c)
{
	return ((c >= 7 && c <= 13) || c == 32);
}
