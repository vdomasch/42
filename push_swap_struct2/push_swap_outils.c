/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:24:13 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/02 15:40:23 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	swap(t_tablist stack, char c)
// {
// 	int	temp;

// 	if (c == 'a')
// 		write(1, "sa\n", 3);
// 	else if (c == 'b')
// 		write(1, "sb\n", 3);
// 	temp = stack.list[stack.len - 1];
// 	stack.list[stack.len - 1] = stack.list[stack.len - 2];
// 	stack.list[stack.len - 2] = temp;
// }

// void	swap_all(t_tablist a, t_tablist b)
// {
// 	swap(a, 0);
// 	swap(b, 0);
// 	printf("ss\n");
// }

// void	push(t_tablist push, t_tablist pull, char c)
// {
// 	if (c == 'a')
// 		write(1, "pa\n", 3);
// 	else if (c == 'b')
// 		write(1, "pb\n", 3);
// 	pull.list[pull.len] = push.list[push.len - 1];
// 	push.list[push.len - 1] = 0;
// }

// void	rotate(t_tablist stack, char c)
// {
// 	int	temp;

// 	if (c == 'a')
// 		write(1, "ra\n", 3);
// 	else if (c == 'b')
// 		write(1, "rb\n", 3);
// 	stack.len--;
// 	temp = stack.list[stack.len];
// 	while (stack.len > 0)
// 	{
// 		stack.list[stack.len] = stack.list[stack.len - 1];
// 		stack.len--;
// 	}
// 	stack.list[stack.len] = temp;
// }

// void	rotate_all(t_tablist a, t_tablist b)
// {
// 	rotate(a, 0);
// 	rotate(b, 0);
// 	write(1, "rr\n", 3);
// }

// void	reverse_rotate(t_tablist stack, char c)
// {
// 	int	temp;
// 	int	i;

// 	if (c == 'a')
// 		write(1, "rra\n", 4);
// 	else if (c == 'b')
// 		write(1, "rrb\n", 4);
// 	stack.len--;
// 	i = 0;
// 	temp = stack.list[i];
// 	while (i < stack.len)
// 	{
// 		stack.list[i] = stack.list[i + 1];
// 		i++;
// 	}
// 	stack.list[i] = temp;
// }

// void	reverse_rotate_all(t_tablist a, t_tablist b, char *str)
// {
// 	reverse_rotate(a, 0);
// 	reverse_rotate(b, 0);
// 	write(1, "rrr\n", 4);
// }
