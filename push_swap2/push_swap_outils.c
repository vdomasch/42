/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:24:13 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/24 13:55:14 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*_sasb(int *list, int len, char c)
{
	int	temp;

	if (c == 'a')
		printf("sa\n");
	else if (c == 'b')
		printf("sb\n");
	temp = list[len - 1];
	list[len - 1] = list[len - 2];
	list[len - 2] = temp;
	return (list);
}

void	_ss(int **list_a, int **list_b, int len)
{
	*list_a = _sasb(*list_a, len, 0);
	*list_b = _sasb(*list_b, len, 0);
	printf("ss\n");
}

void	_papb(int **push, int **pull, int len_push, int len_pull)
{
	int	i;
	int	*list_push;
	int	*list_pull;

	printf("pb\n");
	i = 0;
	list_push = *push;
	list_pull = *pull;
	list_pull[len_pull] = list_push[len_push - 1];
	list_push[len_push - 1] = 0;
}

int	*_rarb(int *list, int len, char c)
{
	int	temp;

	if (c == 'a')
		printf("ra\n");
	else if (c == 'b')
		printf("rb\n");
	len--;
	temp = list[len];
	while (len > 0)
	{
		list[len] = list[len - 1];
		len--;
	}
	list[len] = temp;
	return (list);
}

void	_rr(int **list_a, int **list_b, int len)
{
	*list_a = _rarb(*list_a, len, 0);
	*list_b = _rarb(*list_b, len, 0);
	printf("rr\n");
}

int	*_rrarrb(int *list, int len, char c)
{
	int	temp;
	int	i;

	if (c == 'a')
		printf("rra\n");
	else if (c == 'b')
		printf("rrb\n");
	len--;
	i = 0;
	temp = list[i];
	while (i < len)
	{
		list[i] = list[i + 1];
		i++;
	}
	list[i] = temp;
	return (list);
}

void	_rrr(int **list_a, int **list_b, int len)
{
	*list_a = _rrarrb(*list_a, len, 0);
	*list_b = _rrarrb(*list_b, len, 0);
	printf("rrr\n");
}
