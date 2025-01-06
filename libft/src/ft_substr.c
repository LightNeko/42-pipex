/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:55:48 by znicola           #+#    #+#             */
/*   Updated: 2024/10/13 17:32:01 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_length(size_t slen, unsigned int start, size_t len)
{
	if (start >= slen)
		return (0);
	if (len > slen - start)
		return (slen - start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s);
	arr = malloc((get_length(slen, start, len) + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	if (start >= slen)
	{
		arr[0] = '\0';
		return (arr);
	}
	i = 0;
	while (s[start] && i < len)
	{
		arr[i] = s[start];
		start++;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
