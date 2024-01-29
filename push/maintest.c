/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:19:45 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/24 12:52:37 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int	*list_a;
	int *list_b;
	int len_a;
	int len_b;
	int i;

	i = 1;
	len_a = argc - 1;
	len_b = 0;
	list_a = malloc(sizeof(int) * len_a);
	if (list_a == NULL)
		return (0);
	list_b = malloc(sizeof(int) * len_a);
	if (list_b == NULL)
		return (0);
	while (i <= len_a)
	{
		list_a[len_a - i] = atoi(argv[i]);
		i++;
	}
	i--;
	while (--i >= 0)
		printf("%d ", list_a[i]);
	printf("\n\n");
	list_b[len_b++] = list_a[--len_a];
	list_a[len_a] = 0;
	list_b[len_b++] = list_a[--len_a];
	list_a[len_a] = 0;
	i = 6;
	while (--i >= 0)
		printf("%d ", list_a[i]);
	i = 6;
	printf("\n");
	while (--i >= 0)
	printf("%d ", list_b[i]);
	sort_number(&list_a, &list_b, len_a, len_b);
	return(0);
}

