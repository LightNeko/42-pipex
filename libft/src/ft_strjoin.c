/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:04:19 by znicola           #+#    #+#             */
/*   Updated: 2024/10/05 12:28:31 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	arr = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s1, len_s1 + len_s2 + 1);
	ft_strlcat(arr, s2, len_s1 + len_s2 + 1);
	return (arr);
}
