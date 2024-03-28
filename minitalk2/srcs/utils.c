/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:16:47 by vdomasch          #+#    #+#             */
/*   Updated: 2024/03/28 11:20:20 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strfreejoinfifty(char *s1, const char *s2)
{
	char	*str;

	str = ft_strjoinfifty(s1, s2);
	if (s1)
		free(s1);
	return (str);
}

char	*ft_strjoinfifty(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((100) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < 50)
		str[i] = s1[i];
	j = 0;
	while (j < 49)
		str[i++] = s2[j++];
	return (str);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n--)
	{
		*ptr = (char)c;
		ptr++;
	}
	return (s);
}