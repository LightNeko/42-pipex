/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:08:04 by znicola           #+#    #+#             */
/*   Updated: 2024/10/04 17:41:37 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *sub_s, size_t n)
{
	size_t	i;
	size_t	j;

	if (*sub_s == '\0')
		return ((char *)s);
	i = 0;
	while (s[i] && i < n)
	{
		j = 0;
		while (s[i + j] == sub_s[j] && (i + j) < n)
		{
			if (sub_s[j + 1] == '\0')
				return ((char *)&s[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
