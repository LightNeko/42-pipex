/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:12:28 by znicola           #+#    #+#             */
/*   Updated: 2024/11/01 23:52:23 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_fd(unsigned int num, int fd, int uppercase)
{
	int		count;
	int		result;
	char	*hexdigits;

	if (uppercase)
		hexdigits = "0123456789ABCDEF";
	else
		hexdigits = "0123456789abcdef";
	count = 0;
	if (num / 16 != 0)
	{
		result = ft_puthex_fd(num / 16, fd, uppercase);
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
