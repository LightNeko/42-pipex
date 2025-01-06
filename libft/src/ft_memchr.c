/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:46:43 by znicola           #+#    #+#             */
/*   Updated: 2024/10/06 16:37:27 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_s;
	unsigned char	uc;

	ptr_s = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*ptr_s == uc)
			return ((void *)ptr_s);
		ptr_s++;
	}
	return (NULL);
}
