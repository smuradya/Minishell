/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:18:34 by smuradya          #+#    #+#             */
/*   Updated: 2023/01/23 18:18:37 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char	*c1;
	unsigned const char	*c2;
	size_t				i;

	c1 = (unsigned const char *)s1;
	c2 = (unsigned const char *)s2;
	i = 0;
	while (i < n)
	{
		if ((c1[i] != c2[i] || s1[i] == 0) || s2[i] == 0)
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			len2;
	size_t			len3;
	unsigned int	i;

	if (!s)
		return (NULL);
	len2 = ft_strlen(s);
	len3 = ft_strlen(s + start);
	if (len3 < len)
		len = len3;
	str = malloc(len + 1);
	i = 0;
	while (i < len && start + i < (unsigned int)len2)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		res;
	size_t	i;

	i = 0;
	res = ft_strlen(src);
	if (size == 0)
	{
		return (res);
	}
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size > i)
	{
		dst[i] = 0;
	}
	return (res);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
