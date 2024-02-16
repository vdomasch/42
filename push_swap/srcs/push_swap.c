/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:19:24 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/16 19:49:45 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_swap	*initialize(int argc, char **argv, int i)
{
	t_swap	*list;
	t_swap	*temp;

	list = lstnew_swap(atoi(argv[i]), NULL);
	temp = list;
	while (++i < argc)
	{
		list->next = lstnew_swap(atoi(argv[i]), list);
		list = list->next;
	}
	return (temp);
}

void	free_all(t_swap *list, char **argv, int is_split)
{
	t_swap	*temp;
	int		i;

	i = 0;
	list = lstfirst_swap(list);
	while (list->next)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	free(list);
	if (!is_split)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}

bool	check_error(int argc, char **argv)
{
	size_t	i;
	int	j;

	i = 0;
	if (argc == 1)
		return (1);
	if (argc == 2)
		if (argv[1][0] == '\0')
			return (1);
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]) && !ft_isspace(argv[i][j]) && !(argv[i][j] == '-'))
				return (1);
			if (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1]))
				return (1);
		}
	}
	return (0);
}


int	main(int argc, char **argv)
{
	t_swap	*list;
	int		is_split;
// t_swap	*tmp;

	if (check_error(argc, argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	is_split = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 0;
		while (argv[argc])
			argc++;
		is_split = 0;
	}
	list = initialize(argc, argv, is_split);
	rank_list(list, argc - is_split);
	sort_number(list, argc - is_split, 0);
/*tmp = lstfirst_swap(list);
while (tmp)
{
printf("| rank:%d |", tmp->rank);
printf("v:%d||p:%p||c:%p||n:%p\n", tmp->content, tmp->prev, tmp, tmp->next);
tmp = tmp->next;
}*/
	free_all(list, argv, is_split);
	return (0);
}
