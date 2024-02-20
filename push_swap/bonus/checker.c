/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:17:25 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/20 17:26:18 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../get_next_line/get_next_line.h"

void	checker(t_swap	*list_a)
{
	t_swap	*list_b;
	char	*command;
	int		fd;

	fd = open(1, O_RDONLY);
	while (command)
	{
		command = get_next_line(fd);
		if (ft_strncmp(command, "sa\n", 3))
			swap(list_a, 0);
		if (ft_strncmp(command, "sb\n", 3))
			swap(list_b, 0);
		if (ft_strncmp(command, "pa\n", 3))
			push(list_a, list_b, 0);
		if (ft_strncmp(command, "pb\n", 3))
			push(list_b, list_a, 0);
		if (ft_strncmp(command, "ra\n", 3))
			rotate(list_a, 0);
		if (ft_strncmp(command, "rb\n", 3))
			rotate(list_b, 0);
		if (ft_strncmp(command, "rra\n", 4))
			reverse_rotate(list_a, 0);
		if (ft_strncmp(command, "rrb\n", 4))
			reverse_rotate(list_b, 0);
		if (ft_strncmp(command, "ss\n", 3))
			rule_all(list_a, list_b, "ss", 0);
		if (ft_strncmp(command, "rr\n", 3))
			rule_all(list_a, list_b, "rr", 0);
		if (ft_strncmp(command, "rrr\n", 4))
			rule_all(list_a, list_b, "rrr", 0);
	}
}
