/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:12:28 by znicola           #+#    #+#             */
/*   Updated: 2024/12/01 15:40:01 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		count;
	int		result;
	long	num;

	num = n;
	count = 0;
	if (num < 0)
	{
		count = ft_putchar_fd('-', fd);
		if (count == -1)
			return (-1);
		num = -num;
	}
	if (num / 10 != 0)
	{
		result = ft_putnbr_fd(num / 10, fd);
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
