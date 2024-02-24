/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:04:58 by vdomasch          #+#    #+#             */
/*   Updated: 2024/02/23 17:19:47 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strfreejoin(char *s1, const char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
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
