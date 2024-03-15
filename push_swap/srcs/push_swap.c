/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:19:24 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/14 08:55:52 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*free_all(t_swap *list, char **argv, int is_split)
{
	t_swap	*temp;
	int		i;

	i = 0;
	if (list)
	{
		list = lstfirst_swap(list);
		while (list->next)
		{
			temp = list->next;
			free(list);
			list = temp;
		}
		free(list);
	}
	if (!is_split)
	{
		if (argv)
		{
			while (argv[i])
				free(argv[i++]);
			free(argv);
		}
	}
	return (NULL);
}

t_swap	*initialize(int argc, char **argv, const int is_split)
{
	t_swap	*list;
	t_swap	*temp;
	int		i;

	i = is_split;
	list = lstnew_swap(ft_atoi(argv[i]), NULL);
	if (list->content == 0 && argv[i][0] != '0')
	{
		write(1, "Error\n", 6);
		return (free_all(list, argv, is_split));
	}
	temp = list;
	while (++i < argc)
	{
		list->next = lstnew_swap(ft_atoi(argv[i]), list);
		if (list->next->content == 0 && argv[i][0] != '0')
		{
			write(1, "Error\n", 6);
			return (free_all(list, argv, is_split));
		}
		list = list->next;
	}
	if (check_numbers(list, argc - is_split))
		return (free_all(list, argv, is_split));
	return (temp);
}

int	main(int argc, char **argv)
{
	t_swap	*list;
	int		is_split;

	if (argc == 1 || check_error(argc, argv))
		return (1);
	is_split = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv || (!(*argv) && free_all(NULL, argv, 0) == NULL))
			return (write(1, "Error\n", 6));
		argc = 0;
		while (argv[argc])
			argc++;
		is_split = 0;
	}
	list = initialize(argc, argv, is_split);
	if (!list)
		return (0);
	rank_list(list, argc - is_split);
	sort_number(list, argc - is_split, 0);
	free_all(list, argv, is_split);
	return (0);
}
