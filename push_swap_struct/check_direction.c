/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:22:10 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/29 13:34:55 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*int check_direction()
{
	
}

int	check_direction_a(int *list_a, int len_a, int index)
{
	if ((index + 1) < (len_a / 2))
		return (index * (-1));
	else 
		return (len_a - index);
}
int	check_direction_b(int *list_b, int len_b, int value)
{
	int	i;
	
	i = len_b - 1;
	while (value < list_b[i] && i > 0)
		i--;
	if (i == len_b - 1)
	{
		i = 0;
		while (value > list_b[i] && i < len_b)
			i++;
		if (i == len_b)
			return (lowest_at_bottom_steps(list_b, len_b));
		else
			return (i * (-1));
	}
	else if (i == -1)
		return (lowest_at_bottom_steps(list_b, len_b));
	else if (i + 1 <= len_b / 2)
		return (i * (-1));
	else
		return (len_b - i);
}

int	lowest_at_bottom_direction(int *list, int len)
{
	int	i;
	int	temp;
	int	location;

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
		return (0);
	if (location < len / 2)
		return (location);
	else
		return (len - location);
}*/
