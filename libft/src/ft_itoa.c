/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:32:48 by znicola           #+#    #+#             */
/*   Updated: 2024/10/05 17:47:06 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	if (n < 0)
	{
		count = 1;
		n = -n;
	}
	else
		count = 0;
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	count;
	char	*arr;
	long	num;

	num = n;
	count = count_digits(num);
	arr = malloc((count + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	arr[count] = '\0';
	if (num == 0)
		arr[0] = '0';
	if (num < 0)
	{
		arr[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		arr[--count] = (num % 10) + '0';
		num = num / 10;
	}
	return (arr);
}
