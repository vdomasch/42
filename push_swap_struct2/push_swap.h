/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:50:09 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/02 18:04:00 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"


typedef struct s_swaplist
{
	int				content;
	struct s_swaplist	*prev;
	struct s_swaplist	*next;
}	t_swaplist;

t_swaplist	*ft_lstnewswap(int content, t_swaplist *prev);
//t_swaplist	*ft_lstlastswap(t_swaplist *lst);
//void	ft_lstadd_backswap(t_swaplist **lst, t_swaplist *new);
//void	ft_lstdeloneswap(t_swaplist *lst, void (*del)(void *));
//void	ft_lstclearswap(t_swaplist **lst, void (*del)(void *));


// void	swap(t_tablist list, char c);
// void	swap_all(t_tablist a, t_tablist b);
// void	push(t_tablist push, t_tablist pull, char c);
// void	rotate(t_tablist stack, char c);
// void	rotate_all(t_tablist a, t_tablist b);
// void	reverse_rotate(t_tablist stack, char c);
// void	reverse_rotate_all(t_tablist a, t_tablist b);
// void	type_list(t_tablist a, t_tablist b);
// void	short_list(t_tablist a, t_tablist b);
// void	list_of_two(int *list);
// void	list_of_three(int *list);
// void	list_of_four(t_tablist a, t_tablist b);
// void	long_list(t_tablist a, t_tablist b);

#endif
