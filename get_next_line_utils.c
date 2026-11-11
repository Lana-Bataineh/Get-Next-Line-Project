/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbatai <lalbatai@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:38:00 by lalbatai          #+#    #+#             */
/*   Updated: 2026/11/02 13:35:44 by lalbatai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	ft_str_concat(char *dst, const char *src1, const char *src2)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (src1 && src1[i] != '\0')
		dst[j++] = src1[i++];
	i = 0;
	while (src2 && src2[i] != '\0')
		dst[j++] = src2[i++];
	dst[j] = '\0';
}

char	*read_and_fill(int fd, char *storage_line)
{
	char	*temp_buffer;
	int		read_bytes;

	temp_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buffer)
		return (NULL);
	while (ft_strchr(storage_line, '\n') == NULL)
	{
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(temp_buffer);
			return (NULL);
		}
		else if (read_bytes == 0)
			break ;
		temp_buffer[read_bytes] = '\0';
		storage_line = ft_join(storage_line, temp_buffer);
	}
	free(temp_buffer);
	return (storage_line);
}

char	*extract_line(char *storage_line)
{
	char	*line;
	int		len;

	if (!storage_line || storage_line[0] == '\0')
		return (NULL);
	len = 0;
	while (storage_line[len] != '\n' && storage_line[len] != '\0')
		len++;
	if (storage_line[len] == '\n')
		len++;
	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	len = 0;
	while (storage_line[len] != '\n' && storage_line[len] != '\0')
	{
		line[len] = storage_line[len];
		len++;
	}
	if (storage_line[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}

char	*ft_join(char *storage_line, char *temp_buffer)
{
	char	*mixed_str;
	size_t	len;

	if (!storage_line)
	{
		storage_line = (char *)malloc(sizeof(char));
		if (!storage_line)
			return (NULL);
		storage_line[0] = '\0';
	}
	len = ft_strlen(storage_line) + ft_strlen(temp_buffer);
	mixed_str = (char *)malloc((len + 1) * sizeof(char));
	if (!mixed_str)
		return (free(storage_line), NULL);
	ft_str_concat(mixed_str, storage_line, temp_buffer);
	free(storage_line);
	return (mixed_str);
}

char	*update_storage(char *storage)
{
	char	*temp_storage;
	int		start;
	int		i;

	if (!storage)
		return (NULL);
	start = 0;
	while (storage[start] != '\n' && storage[start] != '\0')
		start++;
	if (storage[start] == '\0')
		return (free(storage), NULL);
	if (storage[start] == '\n')
		start++;
	temp_storage = (char *)malloc((ft_strlen(storage) - start + 1)
			* sizeof(char));
	if (!temp_storage)
		return (free(storage), NULL);
	i = 0;
	while (storage[start])
		temp_storage[i++] = storage[start++];
	temp_storage[i] = '\0';
	free(storage);
	return (temp_storage);
}
