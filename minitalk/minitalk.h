/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:06:04 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/28 13:55:51 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# include <string.h>
# include <stdio.h>

int 	ft_atoi(const char *str);
void    ft_putnbr_fd(int n, int fd);
void    *ft_calloc(size_t nmemb, size_t size);

#endif