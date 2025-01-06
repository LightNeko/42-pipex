/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:08:53 by znicola           #+#    #+#             */
/*   Updated: 2024/10/05 23:45:50 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*arr;
	size_t	i;

	arr = ft_strdup(s);
	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		arr[i] = f(i, arr[i]);
		i++;
	}
	return (arr);
}
