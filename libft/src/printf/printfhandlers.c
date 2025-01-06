/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfhandlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:27:02 by znicola           #+#    #+#             */
/*   Updated: 2024/11/02 14:00:42 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_c(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (ft_putchar_fd(c, 1));
}

int	handle_s(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	return (ft_putstr_fd(str, 1));
}

int	handle_d(va_list args)
{
	int	num;

	num = va_arg(args, int);
	return (ft_putnbr_fd(num, 1));
}

int	handle_u(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (ft_putunsigned_fd(num, 1));
}
