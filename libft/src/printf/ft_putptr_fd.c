/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:12:28 by znicola           #+#    #+#             */
/*   Updated: 2024/11/01 23:53:01 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_fd(uintptr_t num, int fd)
{
	int		count;
	int		result;
	char	*hexdigits;

	hexdigits = "0123456789abcdef";
	count = 0;
	if (num / 16 != 0)
	{
		result = ft_putptr_fd(num / 16, fd);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar_fd(hexdigits[num % 16], fd);
	if (result == -1)
		return (-1);
	count += result;
	return (count);
}
