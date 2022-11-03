/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 16:15:01 by tcensier      #+#    #+#                 */
/*   Updated: 2022/10/28 18:34:56 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static int	function_selector(int c, va_list vl)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += handle_char(va_arg(vl, int));
	else if (c == 's')
		counter += handle_str(va_arg(vl, char *));
	else if (c == 'i' || c == 'd')
		counter += handle_int(va_arg(vl, int));
	else if (c == 'u' || c == 'p' || c == 'x' || c == 'X')
		counter += handle_unsigned(va_arg(vl, void *), c);
	else if (c == '%')
		counter += handle_percent();
	return (counter);
}

static int	conversion_handler(const char *str, va_list vl)
{
	int	index;
	int	len;
	int	arg_len;

	index = 0;
	len = 0;
	arg_len = 0;
	while (str[index] && str)
	{
		if (str[index] == '%')
		{
			index++;
			arg_len += function_selector(str[index], vl);
			index++;
		}
		else
		{
			ft_putchar(str[index]);
			index++;
			len++;
		}
	}
	return (len + arg_len);
}

int	ft_printf(const char *str, ...)
{
	const char	*input;
	va_list		vl;
	int			output_len;

	input = ft_strdup(str);
	output_len = 0;
	va_start(vl, str);
	output_len = conversion_handler(input, vl);
	va_end(vl);
	free((char *) input);
	return (output_len);
}
