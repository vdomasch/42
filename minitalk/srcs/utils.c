/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:39:41 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/28 13:54:50 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int ft_atoi(const char *str)
{
    int         sign;
    long int    number;
    long int    number_cmp;
    size_t      i;  

    i = 0;
    number = 0;
    sign = 1;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    if (str[i] == '-' || str[i] == '+')
        if (str[i++] == '-')
            sign = -1; 
    while (str[i] >= '0' && str[i] <= '9')
    {   
        number_cmp = (number * 10) + (str[i++] - 48);
        if (number > number_cmp && sign > 0)
            return (-1);
        if (number > number_cmp && sign < 0)
            return (0);
        number = number_cmp;
    }   
    return (number * sign);
}

void    ft_putnbr_fd(int n, int fd) 
{
    int sign;

    sign = 1;
    if (n < 0)
    {   
        if (n > -10)
            write(fd, "-", 1); 
        sign = -1; 
    }   
    if (n > 9 || n < -9) 
        ft_putnbr_fd(n / 10, fd);
    n = n % 10 * sign + 48; 
    write(fd, &n, 1); 
}

void    *ft_calloc(size_t nmemb, size_t size)
{
    char    *arr;
    size_t  i;  

    i = 0;
    if (size == 0 || nmemb == 0)
        return (malloc(0));
    if ((nmemb * size) / size != nmemb)
        return (NULL);
    arr = malloc(size * nmemb);
    if (arr == NULL)
        return (NULL);
    while (i < nmemb * size)
        arr[i++] = '\0';
    return (arr);
}

