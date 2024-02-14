/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:19:24 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/12 15:08:52 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swaplist	*initialize(int argc, char **argv)
{
	t_swaplist	*list;
	t_swaplist	*temp;
	int			i;

	i = 1;
	list = lstnew_swap(atoi(argv[1]), NULL);
	temp = list;
	while (++i < argc)
	{
		list->next = lstnew_swap(atoi(argv[i]), list);
		list = list->next;
	}
	return (temp);
}

void	free_list(t_swaplist *list)
{
	t_swaplist	*temp;
	
	while (list->next)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	free(list);
}

int	main(int argc, char **argv)
{
	t_swaplist	*list;
	t_swaplist	*tmp;
	
	if (argc == 1)
		return (printf("\nPAS D'ARGUMENTS\n\n"), 0);
	//argv_to_str(argv);
	list = initialize(argc, argv);
	tmp = list;
	while (tmp)
	{
		printf("| %d |", tmp->rank);
		printf("v:%d||p:%p||c:%p||n:%p\n", tmp->content, tmp->prev, tmp, tmp->next);
		tmp = tmp->next;
	}
	printf("________\n\n");
	rank_list(list, argc - 1);
	sort_number(list, argc - 1);
	//printf("here\n");
	//sort_list_of_three(list);
	while (list->prev)
		list = list->prev;
	tmp = list;
	while (tmp)
	{
		printf("| rank:%d |", tmp->rank);
		printf("v:%d||p:%p||c:%p||n:%p\n", tmp->content, tmp->prev, tmp, tmp->next);
		tmp = tmp->next;
	}
	free_list(list);
	return (0);
}
