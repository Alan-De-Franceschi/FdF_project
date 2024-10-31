/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:26:40 by ade-fran          #+#    #+#             */
/*   Updated: 2023/11/23 14:26:43 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_display_args(const char *fmt, va_list args)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (*fmt == 'd' || *fmt == 'i')
		count += ft_putnbr_fd(va_arg(args, int), 1);
	if (*fmt == 'u')
		count += ft_putnbr_base_fd(va_arg(args, int), "0123456789", 1);
	if (*fmt == 'x')
		count += ft_putnbr_base_fd(va_arg(args, int), base, 1);
	if (*fmt == 'X')
		count += ft_putnbr_base_fd(va_arg(args, int), "0123456789ABCDEF", 1);
	if (*fmt == 'p')
		count += ft_putptr((uintptr_t)va_arg(args, void *), base, 1);
	if (*fmt == 'c')
		count += ft_putchar_fd(va_arg(args, int), 1);
	if (*fmt == '%')
		count += ft_putchar_fd(*fmt, 1);
	if (*fmt == 's')
		count += ft_putstr_fd((char *)va_arg(args, char *), 1);
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!fmt)
		return (-1);
	va_start(args, fmt);
	while (*fmt)
	{
		while (*fmt && *fmt != '%')
		{
			ft_putchar_fd(*fmt++, 1);
			count++;
		}
		if (*fmt == '%')
		{
			fmt++;
			count += ft_display_args(fmt, args);
			fmt++;
		}
	}
	va_end(args);
	return (count);
}
