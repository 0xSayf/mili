/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:52:43 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/20 12:03:42 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/minishell.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!need && !hay)
		return (NULL);
	if (need[0] == '\0')
		return ((char *)hay);
	if (!len)
		return (NULL);
	while (hay[i] != '\0' && i <= len)
	{
		j = 0;
		while (hay[i + j] == need[j] && hay[i + j] && need[j] && j + i < len)
		{
			if (need[j + 1] == '\0')
				return ((char *)&hay[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	size_t	tot;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	tot = ls1 + ls2 + 1;
	ptr = (char *)malloc(sizeof(char) * tot);
	if (!ptr)
		return (NULL);
	ft_memcpy((void *)(ptr), (const void *)s1, ls1);
	ft_memcpy((void *)(ptr + ls1), (const void *)s2, ls2);
	ptr[tot - 1] = '\0';
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

void	freeing(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}