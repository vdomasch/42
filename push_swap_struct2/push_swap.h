/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:50:09 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/06 16:21:17 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"


typedef struct s_swaplist
{
	int					content;
	int					rank;
	struct s_swaplist	*prev;
	struct s_swaplist	*next;
}	t_swaplist;

t_swaplist	*lstnew_swap(int content, t_swaplist *prev);
t_swaplist	*lstlast_swap(t_swaplist *lst);
//t_swaplist	*ft_lstlastswap(t_swaplist *lst);
//void	ft_lstadd_backswap(t_swaplist **lst, t_swaplist *new);
//void	ft_lstdeloneswap(t_swaplist *lst, void (*del)(void *));
//void	ft_lstclearswap(t_swaplist **lst, void (*del)(void *));

void	swap(t_swaplist *stack, char c);
// void	swap_all(t_swaplist *a, t_swaplist *b);
void	push(t_swaplist *push, t_swaplist *pull, char c);
void	rotate(t_swaplist *stack, char c);
// void	rotate_all(t_swaplist *a, t_swaplist *b);
void	reverse_rotate(t_swaplist *stack, char c);
// void	reverse_rotate_all(t_swaplist *a, t_swaplist *b);
void	rule_all(t_swaplist *a, t_swaplist *b, char *str);

void	rank_list(t_swaplist *list, int argc);
void	sort_number(t_swaplist *list_a, int argc);
void	sort_list_of_three(t_swaplist *list);


// void	type_list(t_tablist a, t_tablist b);
// void	short_list(t_tablist a, t_tablist b);
// void	list_of_two(int *list);
// void	list_of_three(int *list);
// void	list_of_four(t_tablist a, t_tablist b);
// void	long_list(t_tablist a, t_tablist b);

#endif
