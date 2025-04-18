/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:38:37 by ozahdi            #+#    #+#             */
/*   Updated: 2024/01/04 08:59:14 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_index(char *all)
{
	int	i;

	i = 0;
	while (all[i])
	{
		if (all[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_line_read(char *all, char *buffer, int fd)
{
	int		n;
	int		index;

	n = read (fd, buffer, BUFFER_SIZE);
	while (n >= 0)
	{
		if (n == 0 && (!all || (all && all[0] == '\0')))
			break ;
		buffer[n] = '\0';
		all = ft_strjoin(all, buffer);
		index = ft_index(all);
		if (index != -1)
			return (all);
		n = read (fd, buffer, BUFFER_SIZE);
		if (!n && ft_strlen(all))
			return (all);
	}
	free (all);
	free (buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*all;
	char		*buffer;
	char		*dst;
	int			a;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	all = ft_line_read(all, buffer, fd);
	if (!all)
		return (NULL);
	a = ft_index(all);
	if (a < 0)
		a = ft_strlen(all);
	dst = ft_before(all, a + 1);
	all = ft_after(all, a);
	free (buffer);
	return (dst);
}
