/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:01:10 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/16 19:21:39 by vdomasch         ###   ########.fr       */
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
		return (count - num);
	else
		return (count);
}

bool	ft_isspace(int c)
{
	return((c >= 7 && c <= 13) || c == 32);
}
