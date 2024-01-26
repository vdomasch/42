/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:24:13 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/26 18:06:32 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(int *list, int len, char c)
{
	int	temp;

	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	temp = list[len - 1];
	list[len - 1] = list[len - 2];
	list[len - 2] = temp;
}

void	swap_all(int **list_a, int **list_b, int len)
{
	swap_ab(*list_a, len, 0);
	swap_ab(*list_b, len, 0);
	printf("ss\n");
}

void	push_b(int **push, int **pull, int len_push, int len_pull)
{
	int	*list_push;
	int	*list_pull;

	write(1, "pb\n", 3);
	list_push = *push;
	list_pull = *pull;
	list_pull[len_pull] = list_push[len_push - 1];
	list_push[len_push - 1] = 0;
}

void	push_a(int **push, int **pull, int len_push, int len_pull)
{
	int	*list_push;
	int	*list_pull;

	write(1, "pa\n", 3);
	list_push = *push;
	list_pull = *pull;
	list_pull[len_pull] = list_push[len_push - 1];
	list_push[len_push - 1] = 0;
}

void	rotate_ab(int *list, int len, char c)
{
	int	temp;

	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	len--;
	temp = list[len];
	while (len > 0)
	{
		list[len] = list[len - 1];
		len--;
	}
	list[len] = temp;
}

void	rotate_all(int **list_a, int **list_b, int len)
{
	rotate_ab(*list_a, len, 0);
	rotate_ab(*list_b, len, 0);
	write(1, "rr\n", 3);
}

void	reverse_rotate_ab(int *list, int len, char c)
{
	int	temp;
	int	i;

	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	len--;
	i = 0;
	temp = list[i];
	while (i < len)
	{
		list[i] = list[i + 1];
		i++;
	}
	list[i] = temp;
}

void	reverse_rotate_all(int **list_a, int **list_b, int len)
{
	reverse_rotate_ab(*list_a, len, 0);
	reverse_rotate_ab(*list_b, len, 0);
	write(1, "rrr\n", 4);

}
