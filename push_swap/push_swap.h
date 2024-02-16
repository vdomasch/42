/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:50:09 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/16 18:41:08 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_swap
{
	int				content;
	int				rank;
	struct s_swap	*prev;
	struct s_swap	*next;
}	t_swap;

t_swap	*lstnew_swap(int content, t_swap *prev);
t_swap	*lstlast_swap(t_swap *lst);
t_swap	*lstfirst_swap(t_swap *lst);
t_swap	*find_rank(t_swap *list, int rank_to_find);

t_swap	*push(t_swap *push, t_swap *pull, char c);
void	swap(t_swap *stack, char c);
// void	swap_all(t_swap *a, t_swap *b);
void	rotate(t_swap *stack, char c);
// void	rotate_all(t_swap *a, t_swap *b);
void	reverse_rotate(t_swap *stack, char c);
// void	reverse_rotate_all(t_swap *a, t_swap *b);
void	rule_all(t_swap *a, t_swap *b, char *str);

int		count_position(t_swap *list, int rank, int num);
bool	ft_isspace(int c);
void	rank_list(t_swap *list, int argc);
void	sort_number(t_swap *list_a, int argc, int num);
void	sort_list_of_three(t_swap *list);

#endif
