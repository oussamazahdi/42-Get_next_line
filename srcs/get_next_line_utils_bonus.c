/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:38:55 by ozahdi            #+#    #+#             */
/*   Updated: 2024/01/04 08:59:31 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
	{
		if (!s1)
			s1 = ft_strdup("");
		else
			return (NULL);
	}
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	while (s1[j])
		ptr[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_before(char *all, int a)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc (sizeof(char) * (a + 1));
	if (!tmp)
		return (NULL);
	while (i < a)
	{
		tmp[i] = all[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_after(char *all, int a)
{
	int		i;
	char	*tmp;
	int		z;

	i = 0;
	z = ft_strlen(all) - a + 1;
	tmp = malloc (z * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[--z] = '\0';
	while (all[a])
		tmp[i++] = all[++a];
	free (all);
	return (tmp);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		size;
	char	*ptr;

	i = 0;
	size = ft_strlen(s);
	ptr = malloc(size + 1);
	if (!ptr)
		return (0);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
