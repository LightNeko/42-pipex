/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:10:53 by znicola           #+#    #+#             */
/*   Updated: 2024/10/06 17:25:20 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*allocated_memory;

	if (num != 0 && size != 0 && num > SIZE_MAX / size)
		return (NULL);
	allocated_memory = malloc(num * size);
	if (!allocated_memory)
		return (NULL);
	ft_memset(allocated_memory, 0, num * size);
	return (allocated_memory);
}
