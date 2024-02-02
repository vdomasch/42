/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:58:27 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/02 10:09:44 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int	*list;
	int	len;
}	t_list;

void	sort_number(t_list *a, t_list *b)
{
	int	i;
	
	a->len = 10;
	while (i < a->len)
	{
		
	}
}

int	main(void)
{
	t_list	a;
	t_list	b;
	int	i;

	i = 0;
	a.list = malloc(sizeof(int) * 10);
	b.list = malloc(sizeof(int) * 10);
	while (i < 10)
	{
		a.list[i] = i * 2;
		b.list[i] = i * 2 + 1;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		printf("% 3d    %3d\n", a.list[i], b.list[i]);
		i++;
	}
	return (0);
}