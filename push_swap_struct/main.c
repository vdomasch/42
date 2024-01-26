/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:19:24 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/26 17:57:27 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_list	list;

	i = 0;
	j = 1;
	list.len_a = argc - 1;
	list.len_b = 0;
	list.list_a = malloc(sizeof(int) * list.len_a);
	if (!list.list_a)
		return (0);
	list.list_b = malloc(sizeof(int) * list.len_a);
	if (!list.list_b)
	{
		free(list.list_a);
		return (0);
	}
	while (j <= list.len_a)
	{
		list.list_a[list.len_a - j] = atoi(argv[j]);
		j++;
	}
	type_list(list);
	j--;
	printf("\n la | lb\n---------");
	while (j-- > 0)
		printf("\n%3d | %d", list.list_a[j], list.list_b[j]);
	free(list.list_b);
	free(list.list_a);
	return (0);
}
