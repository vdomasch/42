/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:01:10 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/05 15:47:36 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_list(t_swaplist *list, int argc)
{
	int			i;
	int			temp;
	t_swaplist	*start;

	i = -1;
	start = list;
	while (i++ < argc)
	{
		temp = INT_MAX;
		while (list)
		{
			if (list->content < temp && list->rank == -1)
				temp = list->content;
			list = list->next;
		}
		list = start;
		while (list)
		{
			if (list->content == temp)
				list->rank = i;
			list = list->next;
		}
		list = start;
	}
}
