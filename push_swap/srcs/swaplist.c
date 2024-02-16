/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaplist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:53:22 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/16 18:01:57 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_swap	*lstnew_swap(int content, t_swap *prev)
{
	t_swap	*list;

	list = (t_swap *)malloc(sizeof(t_swap));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->rank = -1;
	list->next = NULL;
	list->prev = prev;
	return (list);
}

t_swap	*lstlast_swap(t_swap *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_swap	*lstfirst_swap(t_swap *lst)
{
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

t_swap	*find_rank(t_swap *list, int rank_to_find)
{
	while (list->prev)
		list = list->prev;
	while (list->rank != rank_to_find)
		list = list->next;
	return (list);
}
