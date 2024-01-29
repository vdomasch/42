/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:01:59 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/25 14:03:21 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*check_list(int *list_a, int *list_b, int len)
{
	if (len < 5)
		list_a = short_list(list_a, list_b, len);
	else
		list_a = long_list(list_a, list_b, len);
	return (list_a);
}

int	*short_list(int *list_a, int *list_b, int len)
{
	if (len == 2)
		list_a = list_of_two(list_a);
	else if (len == 3)
		list_a = list_of_three(list_a);
	else
		list_a = list_of_four(list_a, list_b, 4);
	return (list_a);
}

int	*list_of_two(int *list)
{
	if (list[1] < list[0])
		return (list);
	list = _sasb(list, 2, 'a');
	printf("sa\n");
	return (list);
}

int	*list_of_three(int *list)
{
	if (list[2] < list[1] && list[1] < list[0])
		return (list);
	else if ((list[2] < list[1] && list[2] < list[0] && list[1] > list[0])
		|| (list[2] < list[1] && list[2] > list[0] && list[1] > list[0]))
		list = _rrarrb(list, 3, 'a');
	else if (list[2] > list[1] && list[2] > list[0])
		list = _rarb(list, 3, 'a');
	if (list[2] > list[1] && list[2] < list[0] && list[1] < list[0])
		list = _sasb(list, 3, 'a');
	return (list);
}

int	*list_of_four(int *list_a, int *list_b, int len)
{
	int	i;
	int	temp;
	int	location;

	i = 1;
	temp = list_a[0];
	while (i < 4)
	{
		if (list_a[i] < temp)
		{
			temp = list_a[i];
			location = i;
		}
		i++;
	}
	if (location == 0)
		list_a = _rrarrb(list_a, len, 'a');
	else if (location == 1)
	{
		list_a = _rarb(list_a, len, 'a');
		location = 2;
	}
	if (location == 2)
		list_a = _sasb(list_a, len, 'a');
	_papb(&list_a, &list_b, 4, 0);
	printf("pb\n");
	list_a = list_of_three(list_a);
	_papb(&list_b, &list_a, 1, 3);
	printf("pa\n");
	return (list_a);
}

int	*long_list(int *list_a, int *list_b, int len_a)
{
	int	len_b;
	int j;

	len_b = 0;
	_papb(&list_a, &list_b, len_a--, len_b++);
	_papb(&list_a, &list_b, len_a--, len_b++);
	while (len_a > 0)
		sort_number(&list_a, &list_b, len_a--, len_b++);
	printf("___\n");
	list_b = lowest_at_bottom(list_b, len_b);
	//list_a = list_of_three(list_a);
	/*while (len_b >= 0)
		sort_number_list_a(&list_b, &list_a, len_b--, len_a++);*/
	return (list_a);
}

void	sort_number(int **list_a, int **list_b, int len_a, int len_b)
{
	int	index;

	index = len_a - 1;
	//index = check_number_steps(*list_a, *list_b, len_a, len_b);
	//rotate_a(*list_a, len_a, index);
	rotate_b(*list_a, *list_b, index, len_b);
	_papb(list_a, list_b, len_a, len_b);
}

void	sort_number_list_a(int **list_a, int **list_b, int len_a, int len_b)
{
	int	index;

	index = len_a - 1;
	index = check_number_steps(*list_a, *list_b, len_a, len_b);
	//rotate_a(*list_a, len_a, index);
	rotate_b(*list_b, *list_a, index, len_a);
	_papb(list_a, list_b, len_a, len_b);
}

int		check_number_steps(int *list_a, int *list_b, int len_a, int len_b)
{
	int	i;
	int	j;
	int	temp;
	int	nb_stps;
	int	location;
	
	i = len_a;
	location = -1;
	while (--i >= 0)
	{	
		/*j = 0;
		while (list_a[i] > list_b[j] && j < len_b)
			j++;
		temp = number_steps(len_b, j) + number_steps(len_a, i) + 1;
		if (temp < nb_stps || location == -1)
		{
			nb_stps = temp;
			location = i;
		}*/
	}
	return (location);
}

/*int		number_steps(int len, int i)
{
	if (i < (len / 2))
		return (i + 1);
	return (len - i);	
}*/

void	rotate_a(int *list_a, int len_a, int index)
{
	if (index < len_a / 2)
		while (index-- >= 0)
			list_a = _rrarrb(list_a, len_a, 'a');
	else
		while (index++ < len_a)
			list_a = _rarb(list_a, len_a, 'a');
}
			
void	rotate_b(int *list_a, int *list_b, int index, int len_b)
{
	int	j;
	int i;

	j = len_b - 1;
	i = 0;
	while (list_a[index] < list_b[j] && j > 0)
		j--;
	if (j == len_b - 1)
	{
		j = 0;
		while (list_a[index] > list_b[j] && j < len_b)
			j++;
		if (j == len_b)
			list_b = lowest_at_bottom(list_b, len_b);
		else while (j-- > 0)			
			list_b = _rrarrb(list_b, len_b, 'b');
	}
	else if (j == 0)
		list_b = lowest_at_bottom(list_b, len_b);
	else if (j + 1 <= len_b / 2)
		while (j-- > 0)
			list_b = _rrarrb(list_b, len_b, 'b');
	else
		while (++j < len_b)
			list_b = _rarb(list_b, len_b, 'b');
}

int	*lowest_at_bottom(int *list, int len)
{
	int	i;
	int	temp;
	int location;

	i = 0;
	temp = list[i];
	location = i;
	while (++i < len)
	{
		if (list[i] < temp)
		{
			temp = list[i];
			location = i;
		}
	}
	if (location == 0)
		return (list);
	if (location < len / 2)
		while (location-- > 0)
			list = _rrarrb(list, len, 'b');
	else
		while (location++ < len)
			list = _rarb(list, len, 'b');
	return (list);
}
