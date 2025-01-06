/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:12:28 by znicola           #+#    #+#             */
/*   Updated: 2024/11/01 23:52:41 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_fd(unsigned int n, int fd)
{
	int				count;
	int				result;
	unsigned long	num;

	num = n;
	count = 0;
	if (num / 10 != 0)
	{
		result = ft_putunsigned_fd(num / 10, fd);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar_fd((num % 10) + '0', fd);
	if (result == -1)
		return (-1);
	count += result;
	return (count);
}
