/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:50:09 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/29 14:03:49 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int	*list_a;
	int	*list_b;
	int	len_a;
	int	len_b;
}	t_list;

void	swap_ab(int *list, int len, char c);
void	swap_all(int **list_a, int **list_b, int len);
void	push_a(int **push, int **pull, int len_push, int len_pull);
void	push_b(int **push, int **pull, int len_push, int len_pull);
void	rotate_ab(int *list, int len, char c);
void	rotate_all(int **list_a, int **list_b, int len);
void	reverse_rotate_ab(int *list, int len, char c);
void	reverse_rotate_all(int **list_a, int **list_b, int len);
void	type_list(t_list list);
void	short_list(t_list list);
void	list_of_two(int *list_a);
void	list_of_three(int *list);
void	list_of_four(t_list list);
int		*long_list(t_list list);
void	sort_number(t_list *list);
void	sort_number_a(t_list *list);
void	ready_a(int *list_b, int *list_a, int index, int len_a);
void	ready_b(int *list_a, int *list_b, int index, int len_b);
int		*lowest_at_bottom(int *list, int len);
int		*lowest_at_top(int *list, int len);
int		check_less_steps_pb(int *list_a, int *list_b, int len_a, int len_b);
int		steps_list_a(int *list_a, int len_a, int index);
int		steps_list_b(int *list_b, int len_b, int value);
int		lowest_at_bottom_steps(int *list, int len);

#endif
