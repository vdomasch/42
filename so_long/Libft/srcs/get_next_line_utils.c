/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:04:58 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/22 16:22:53 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strfreejoin(char *s1, const char *s2)
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
	if (!line)
		return (NULL);
	line[0] = '\n';
	line[1] = '\0';
	return (line);
}
