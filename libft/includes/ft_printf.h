/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:02:50 by znicola           #+#    #+#             */
/*   Updated: 2024/12/01 16:27:43 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include "libft.h"

int		handle_c(va_list args);
int		handle_s(va_list args);
int		handle_d(va_list args);
int		handle_u(va_list args);
int		handle_p(va_list args);
int		handle_x(va_list args);
int		handle_upperx(va_list args);
int		handle_percent(void);
int		ft_putunsigned_fd(unsigned int n, int fd);
int		ft_puthex_fd(unsigned int num, int fd, int uppercase);
int		ft_putptr_fd(uintptr_t num, int fd);

#endif
