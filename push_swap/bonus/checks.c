/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:41:09 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/20 12:08:13 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc == 1)
		return (1);
	if (argc == 2)
		if (argv[1][0] == '\0')
			return (2);
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]) && !ft_isspace(argv[i][j])
			&& !(argv[i][j] == '-'))
				return (write(1, "Error\n", 6));
			if (argv[i][j] == '-' && !ft_isdigit(argv[i][j + 1]))
				return (write(1, "Error\n", 6));
		}
	}
	return (0);
}

int	check_sorted(t_swap *list, int argc)
{
	int	i;

	i = 1;
	list = lstfirst_swap(list);
	while (list->next)
	{
		if (list->next->rank != list->rank + 1)
			return (0);
		list = list->next;
		i++;
	}
	if (argc == i)
		return (1);
	return (0);
}

int	check_numbers(t_swap *list, int argc)
{
	t_swap	*check;

	list = lstfirst_swap(list);
	while (list)
	{
		check = list->next;
		while (check)
		{
			if (list->content == check->content)
				return (write(1, "Error\n", 6));
			check = check->next;
		}
		list = list->next;
	}
	argc = argc + 0;
	return (0);
}
