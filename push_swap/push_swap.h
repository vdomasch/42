/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:50:09 by vdomasch          #+#    #+#             */
/*   Updated: 2024/01/17 18:12:29 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

int	*_sasb(int *list, int len);
void _ss(int **list_a, int **list_b, int len);
void _papb(int **push, int **pull, int *len);
int	*_rarb(int *list, int len);
void _rr(int **list_a, int **list_b, int len);
int	*_rrarrb(int *list, int len);
void _rrr(int **list_a, int **list_b, int len);

#endif
