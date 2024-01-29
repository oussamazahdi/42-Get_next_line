/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:38:50 by ozahdi            #+#    #+#             */
/*   Updated: 2024/01/04 09:13:22 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

size_t	ft_strlen(char *s);
int		ft_index(char *all);
char	*ft_strdup(char *s);
char	*get_next_line(int fd);
char	*ft_after(char *all, int a);
char	*ft_before(char *all, int a);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_line_read(char *all, char *buffer, int fd);

#endif
