/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:19:24 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/06 15:04:11 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	*string_input(char *str)
// {
// 	char	**args;
// 	int		*stack;
// 	int		i;

// 	i = 0;
// 	args = ft_split(str, ' ');
// 	while (args[i])
// 	{
// 		stack[i] = ft_atoi(args[i]);
// 		i++;
// 	}
// 	return (stack);
// }

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
	t_swaplist	*list_b;
	t_swaplist	*tmp;

	if (argc == 1)
		return (printf("\nPAS D'ARGUMENTS\n\n"), 0);
	list = initialize(argc, argv);
	tmp = list;
	while (tmp)
	{
		printf("| %d |", tmp->content);
		//printf("v:%d||p:%p||c:%p||n:%p\n", tmp->content, tmp->prev, tmp, tmp->next);
		tmp = tmp->next;
	}
	printf("\n________\n");
	list_b = list;
	list = list->next;
	push(list->prev, list_b, 'b');
	// list = list->next;
	// push(list->prev, list_b, 'b');
	// list = list->next;
	// list_b = list_b->prev; 
	// push(list->prev, list_b, 'b');
	tmp = list;
	printf("\n");
	while (tmp)
	{
		printf("| v:%d |", tmp->content);
		//printf("v:%d||p:%p||c:%p||n:%p\n", tmp->content, tmp->prev, tmp, tmp->next);
		tmp = tmp->next;
	}
	printf("\n");
	while (list_b->prev)
		list_b = list_b->prev;
	tmp = list_b;
	while (tmp)
	{
		printf("| v:%d |", tmp->content);
	//	printf("v:%d||p:%p||c:%p||n:%p\n", tmp->content, tmp->prev, tmp, tmp->next);
		tmp = tmp->next;
	}
	free_list(list);
	free_list(list_b);
	return (0);
}
