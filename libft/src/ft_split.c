/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:55:38 by znicola           #+#    #+#             */
/*   Updated: 2025/01/06 23:31:34 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_delimiters(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (s[0] != c && s[0] != '\0')
		count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static void	fill_substrings(char **arr, const char *s, char c, size_t count)
{
	const char	*ptr;
	size_t		i;

	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		ptr = ft_strchr(s, c);
		if (ptr)
			arr[i] = ft_substr(s, 0, ptr - s);
		else
			arr[i] = ft_substr(s, 0, ft_strlen(s));
		if (!arr[i])
			return ;
		s = ptr + 1;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	count;
	size_t	i;

	count = count_delimiters(s, c);
	arr = malloc((count + 1) * sizeof(*arr));
	if (!arr)
		return (NULL);
	fill_substrings(arr, s, c, count);
	i = 0;
	while (i < count)
	{
		if (!arr[i])
		{
			while (i > 0)
				free(arr[--i]);
			free(arr);
			return (NULL);
		}
		i++;
	}
	arr[count] = NULL;
	return (arr);
}
