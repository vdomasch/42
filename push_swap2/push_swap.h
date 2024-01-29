/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:50:09 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/25 14:05:53 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list 
{
	int	*list_a;
	int	*list_b;
	int	len_a;
	int	len_b;
}	t_list;

int		*_sasb(int *list, int len, char c);
void	_ss(int **list_a, int **list_b, int len);
void	_papb(int **push, int **pull, int len_push, int len_pull);
int		*_rarb(int *list, int len, char c);
void	_rr(int **list_a, int **list_b, int len);
int		*_rrarrb(int *list, int len, char c);
void	_rrr(int **list_a, int **list_b, int len);
int		*check_list(int *list_a, int *list_b, int len);
int		*short_list(int *list_a, int *list_b, int len);
int		*list_of_two(int *list_a);
int		*list_of_three(int *list);
int		*list_of_four(int *list_a, int *list_b, int len);
int		*long_list(int *list_a, int *list_b, int len_a);
void	sort_number(int **list_a, int **list_b, int len_a, int len_b);
//void	sort_number_list_b(int **list_a, int **list_b, int len_a, int len_b);
void	sort_number_list_a(int **list_a, int **list_b, int len_a, int len_b);
int		number_steps(int len_b, int j);
int		check_number_steps(int *list_a, int *list_b, int len_a, int len_b);
void	rotate_a(int *list_a, int len_a, int index);
void	rotate_b(int *list_a, int *list_b, int index, int len_b);
int		*lowest_at_bottom(int *list, int len);

#endif
