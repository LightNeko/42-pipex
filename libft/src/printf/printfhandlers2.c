/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfhandlers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:27:02 by znicola           #+#    #+#             */
/*   Updated: 2024/11/02 14:09:50 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_p(va_list args)
{
	void			*ptr;
	uintptr_t		address;
	int				count;

	ptr = va_arg(args, void *);
	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	address = (uintptr_t)ptr;
	count = ft_putstr_fd("0x", 1);
	count += ft_putptr_fd(address, 1);
	return (count);
}

int	handle_x(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (ft_puthex_fd(num, 1, 0));
}

int	handle_upperx(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (ft_puthex_fd(num, 1, 1));
}

int	handle_percent(void)
{
	return (ft_putchar_fd('%', 1));
}
