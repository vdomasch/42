/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:19:24 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/17 18:12:29 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int j;
	int len;
	int *list_a;
	int	*list_b;

	i = 0;
	j = 0;
	len = argc - 1;
	list_a = malloc(sizeof(int) * len);
	list_b = malloc(sizeof(int) * len);
	if (!list_a || !list_b)
		return (0);
	while (i < len)
	{
		list_b[i] = i + 1;
		i++;
	}
	while (j < len)
	{
		list_a[j] = atoi(argv[j + 1]);
		j++;
	}
	while (i-- > 0)
	{
		printf("%d  %d\n", list_a[i], list_b[i]);
	}
	_rr(&list_a, &list_b, len - 1);
	j = len;
	while (j-- > 0)
		printf("\n%d  %d", list_a[j], list_b[j]);
	free(list_a);
	free(list_b);
	return (0);
}