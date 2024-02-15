/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:19:24 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/15 18:57:29 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


t_swaplist	*initialize(int argc, char **argv, int i)
{
	t_swaplist	*list;
	t_swaplist	*temp;

	list = lstnew_swap(atoi(argv[i]), NULL);
	temp = list;
	while (++i < argc)
	{
		list->next = lstnew_swap(atoi(argv[i]), list);
		list = list->next;
	}
	return (temp);
}

void	free_all(t_swaplist *list, char **argv, int is_split)
{
	t_swaplist	*temp;
	int			i;
	
	i = 0;
	while (list->next)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	free(list);
	if (!is_split)
	{
		while(argv[i])
			free(argv[i++]);
		free(argv);
	}
}

int	main(int argc, char **argv)
{
	t_swaplist *save;
	
	t_swaplist	*list;
	t_swaplist	*tmp;
	int			is_split;
	
	is_split = 1;
	if (argc == 1)
		return (printf("\nPAS D'ARGUMENTS\n\n"), 0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 0;
		while (argv[argc])
			argc++;
		is_split = 0;
	}
	list = initialize(argc, argv, is_split);
	tmp = list;
	while (tmp)
	{
		printf("| %d |", tmp->rank);
		printf("v:%d||p:%p||c:%p||n:%p\n", tmp->content, tmp->prev, tmp, tmp->next);
		tmp = tmp->next;
	}
	printf("________\n\n");
	rank_list(list, argc - is_split, &save);
	sort_number(list, argc - is_split, 0);
	//sort_number2(&list, argc - is_split);
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
	printf("\n\n| rank:%d |", save->rank);
	printf("v:%d||p:%p||c:%p||n:%p\n", save->content, save->prev, save, save->next);
	free_all(list, argv, is_split);
	return (0);
}
