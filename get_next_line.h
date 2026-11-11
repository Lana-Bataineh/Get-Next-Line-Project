/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbatai <lalbatai@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:40:28 by lalbatai          #+#    #+#             */
/*   Updated: 2026/11/03 15:45:42 by lalbatai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_and_fill(int fd, char *storage_line);
char	*extract_line(char *storage_line);
char	*ft_join(char *storage_line, char *temp_buffer);
char	*update_storage(char *storage);
void	ft_str_concat(char *dst, const char *src1, const char *src2);
char	*ft_strchr(const char *str, char ch);
int		ft_strlen(char *str);

#endif
