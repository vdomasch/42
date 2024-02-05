/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:19:24 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/05 15:09:46 by vdomasch         ###   ########.fr       */
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
	//t_swaplist	*list2;
	t_swaplist	*tmp;
	//t_swaplist	*tmp2;

	//list2 = lstnew_swap(0, NULL);
	if (argc == 1)
		return (printf("\nPAS D'ARGUMENTS\n\n"), 0);
	list = initialize(argc, argv);
	tmp = list;
	//tmp2 = list2;
	while (tmp)
	{
		printf("v:%d||p:%p||c:%p||n:%p\n", tmp->content, tmp->prev, tmp, tmp->next);
		tmp = tmp->next;
	}
	// printf("\n");
	// while (tmp2)
	// {
	// 	printf("v:%d||p:%p||c:%p||n:%p\n", tmp2->content, tmp2->prev, tmp2, tmp2->next);
	// 	tmp2 = tmp2->next;
	// }
	//tmp = list->next;
	//tmp2 = list2;
	rule_all(list, NULL, "rrr");
	//list2 = list2->prev;
	//tmp2 = list2;
	list = list->prev;
	tmp = list;
	rule_all(NULL, list, "rrr");
	list = list->prev;
	tmp = list;
	printf("_________\n\n");
	while (tmp)
	{
		printf("v:%d||p:%p||c:%p||n:%p\n", tmp->content, tmp->prev, tmp, tmp->next);
		tmp = tmp->next;
	}
	// printf("\n");
	// while (tmp2)
	// {
	// 	printf("v:%d||p:%p||c:%p||n:%p\n", tmp2->content, tmp2->prev, tmp2, tmp2->next);
	// 	tmp2 = tmp2->next;
	// }
	free_list(list);
	//free_list(list2);
	return (0);

	/*int		i;
	int		j;
	t_tablist	a;
	t_tablist	b;

	i = 0;
	j = 1;
	if (argc == 2)
		a.list = string_input(argv[1]);
	else
	{
		a.len = argc - 1;
		b.len = 0;
		a.list = malloc(sizeof(int) * a.len);
		if (!a.list)
			return (0);
		b.list = malloc(sizeof(int) * a.len);
		if (!b.list)
		{
			free(a.list);
			return (0);
		}
		while (j <= a.len)
		{
			a.list[a.len - j] = ft_atoi(argv[j]);
			b.list[j - 1] = j - 1;
			j++;
		}
	}
	type_list(a, b);
	j--;
	printf("\n la | lb\n---------");
	while (j-- > 0)
		printf("\n%3d | %d", a.list[j], b.list[j]);
	//free(b.list);
	free(a.list);
	return (0);*/
}
