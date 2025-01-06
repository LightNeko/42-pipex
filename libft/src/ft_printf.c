/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:59:28 by znicola           #+#    #+#             */
/*   Updated: 2024/12/01 16:26:47 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flags(const char **str, va_list args)
{
	if (**str == 'c')
		return (handle_c(args));
	else if (**str == 's')
		return (handle_s(args));
	else if (**str == 'p')
		return (handle_p(args));
	else if (**str == 'd' || **str == 'i')
		return (handle_d(args));
	else if (**str == 'u')
		return (handle_u(args));
	else if (**str == 'x')
		return (handle_x(args));
	else if (**str == 'X')
		return (handle_upperx(args));
	else if (**str == '%')
		return (handle_percent());
	else
		return (-1);
}

static int	process_printf(const char *str, va_list args)
{
	int	len;
	int	result;

	len = 0;
	while (*str != '\0')
	{
		while (*str == '%')
		{
			str++;
			result = check_flags(&str, args);
			if (result == -1)
				return (-1);
			len += result;
			str++;
		}
		if (*str == '\0')
			break ;
		result = ft_putchar_fd(*str, 1);
		if (result == -1)
			return (-1);
		len += result;
		str++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = process_printf(str, args);
	va_end(args);
	return (len);
}
