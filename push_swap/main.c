/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:19:24 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/17 14:29:51 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int j;
	int *list_a;
	int	*list_b;

	i = 0;
	j = 0;
	list_a = malloc(sizeof(int) * (argc - 1));
	list_b = malloc(sizeof(int) * (argc - 1));
	while (i < argc - 1)
		list_b[i++] = i;
	while (j < argc - 1)
	{
		list_a[j] = atoi(argv[j + 1]);
		j++;
	}
	while (i-- > 0)
		printf("%d\n", list_a[i]);
	_ss(&list_a, &list_b, argc - 1);
	while (j-- > 0)
		printf("%d\n", list_a[j]);
	return (0);
}