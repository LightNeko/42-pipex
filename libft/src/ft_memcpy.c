/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:43:55 by znicola           #+#    #+#             */
/*   Updated: 2024/10/06 16:41:43 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destptr;
	const unsigned char	*srcptr;

	if (!dest && !src)
		return (NULL);
	destptr = (unsigned char *)dest;
	srcptr = (const unsigned char *)src;
	while (n--)
	{
		*destptr = *srcptr;
		destptr++;
		srcptr++;
	}
	return (dest);
}
