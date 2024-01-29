/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:19:24 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/24 12:56:12 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;
	int	*list_a;
	int	*list_b;

	i = 0;
	j = 1;
	len = argc - 1;
	list_a = malloc(sizeof(int) * len);
	if (!list_a)
		return (0);
	list_b = malloc(sizeof(int) * len);
	if (!list_b)
		return (0);
	while (j <= len)
	{
		list_a[len - j] = atoi(argv[j]);
		list_b[len - j] = 0;
		j++;
	}
	list_a = check_list(list_a, list_b, len);
	j--;
	while (j-- > 0)
		printf("\n%d  %d", list_a[j], list_b[j]);
	free(list_b);
	free(list_a);
	return (0);
}
