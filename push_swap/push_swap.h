/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:50:09 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/14 08:43:51 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_swap
{
	int				content;
	int				rank;
	struct s_swap	*prev;
	struct s_swap	*next;
}	t_swap;

/****************************************************************************/
/*										LIST								*/
/****************************************************************************/

t_swap	*lstnew_swap(int content, t_swap *prev);
t_swap	*lstlast_swap(t_swap *lst);
t_swap	*lstfirst_swap(t_swap *lst);
t_swap	*find_rank(t_swap *list, int rank_to_find);

/****************************************************************************/
/*										RULES								*/
/****************************************************************************/

t_swap	*push(t_swap *push, t_swap *pull, char c, int *error);
void	swap(t_swap *stack, char c, int *error);
void	rotate(t_swap *stack, char c, int *error);
void	reverse_rotate(t_swap *stack, char c, int *error);
void	rule_all(t_swap *a, t_swap *b, char *str, int *error);

/****************************************************************************/
/*										CHECKS								*/
/****************************************************************************/

int		check_error(int argc, char **argv);
int		check_sorted(t_swap *list, int argc);
int		check_numbers(t_swap *list, int argc);

/****************************************************************************/
/*										UTILS								*/
/****************************************************************************/

int		count_position(t_swap *list, int rank, int num);
bool	ft_isspace(int c);
void	rank_list(t_swap *list, int argc);
t_swap	*detain_number(t_swap *list_a, t_swap *list_b, int num, int *detain);

/****************************************************************************/
/*										SORT								*/
/****************************************************************************/

void	sort_number(t_swap *list_a, int argc, int num);

/****************************************************************************/
/*										BONNUS								*/
/****************************************************************************/

void	checker(t_swap	*list_a);

#endif
