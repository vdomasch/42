/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:53:22 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/02 16:17:22 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swaplist	*ft_lstnewswap(int content, t_swaplist *prev)
{
	t_swaplist	*list;

	list = (t_swaplist *)malloc(sizeof(t_swaplist));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	list->prev = prev;
	return (list);
}
