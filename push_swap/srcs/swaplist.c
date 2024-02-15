/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaplist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:53:22 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/15 13:04:54 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_swaplist	*lstnew_swap(int content, t_swaplist *prev)
{
	t_swaplist	*list;

	list = (t_swaplist *)malloc(sizeof(t_swaplist));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->rank = -1;
	list->next = NULL;
	list->prev = prev;
	return (list);
}

t_swaplist	*lstlast_swap(t_swaplist *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}
