/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:58:05 by aboiarin          #+#    #+#             */
/*   Updated: 2023/06/20 15:46:04 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_newline(const char *s)
{
	while (*s++)
	{
		if (*s == '\n')
			return (1);
	}
	return (0);
}

void	ft_free_str(char **s1, char **s2, char **s3)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	if (s3 && *s3)
	{
		free(*s3);
		*s3 = NULL;
	}
}

void	*ft_memzero(size_t len, size_t size)
{
	void			*r;
	unsigned char	*p;
	size_t			a;

	a = len * size;
	r = malloc(a);
	if (!r)
		return (NULL);
	p = (unsigned char *)r;
	while (a != 0)
	{
		*p = '\0';
		p++;
		a--;
	}
	return (r);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	if (!src)
		return (ft_strdup(""));
	i = 0;
	while (src[i])
		i++;
	dest = ft_memzero(i + 1, sizeof * dest);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_join(const char *s1, const char *s2)
{
	char	*r;
	int		j;
	int		i;

	j = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1 && s1[j])
		j++;
	i = 0;
	while (s2 && s2[i])
		i++;
	r = ft_memzero(j + i + 1, sizeof * r);
	if (!r)
		return (NULL);
	j = -1;
	while (s1 && s1[++j])
		r[j] = s1[j];
	i = -1;
	while (s2 && s2[++i])
		r[j + i] = s2[i];
	return (r);
}
