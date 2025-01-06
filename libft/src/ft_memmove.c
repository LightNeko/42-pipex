/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:43:00 by znicola           #+#    #+#             */
/*   Updated: 2024/10/06 17:14:33 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destptr;
	const unsigned char	*srcptr;

	if (!dest && !src)
		return (NULL);
	destptr = (unsigned char *)dest;
	srcptr = (unsigned char *)src;
	if ((destptr < srcptr + n) && !(destptr < srcptr))
	{
		while (n--)
			destptr[n] = srcptr[n];
	}
	else
		while (n--)
			*destptr++ = *srcptr++;
	return (dest);
}
