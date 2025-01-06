/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:00:22 by znicola           #+#    #+#             */
/*   Updated: 2024/12/01 15:39:48 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;
	int	result;

	len = 0;
	while (*s)
	{
		result = ft_putchar_fd(*s, fd);
		if (result == -1)
			return (-1);
		len += result;
		s++;
	}
	return (len);
}
