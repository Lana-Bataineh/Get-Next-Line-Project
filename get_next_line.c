/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbatai <lalbatai@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:40:06 by lalbatai          #+#    #+#             */
/*   Updated: 2026/11/02 11:44:16 by lalbatai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage_line = read_and_fill(fd, storage_line);
	if (!storage_line)
		return (NULL);
	line = extract_line(storage_line);
	if (!line)
	{
		free(storage_line);
		storage_line = NULL;
		return (NULL);
	}
	storage_line = update_storage(storage_line);
	return (line);
}

int	ft_strlen(char *str)
{
	int	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *str, char ch)
{
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	if (ch == '\0')
		return ((char *)str);
	return (NULL);
}
