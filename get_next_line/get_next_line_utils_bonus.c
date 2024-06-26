/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:04:58 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/06 10:35:44 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	int		i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
	{
		free(s1);
		return (NULL);
	}
	i = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*line_feed(void)
{
	char	*line;

	line = malloc(sizeof(char) * 2);
	line[0] = '\n';
	line[1] = '\0';
	return (line);
}
