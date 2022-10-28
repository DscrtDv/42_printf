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
#include "printf.h"
#include <stdio.h>


int	function_select(const char *str, va_list vl)
{
	size_t	i;
	char	*set;

	set = "cspdiuxX%";
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_strchr(set, str[i]))
		}
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	vl;
	char *str_arg;
	int i = 0; 
	int j = 0;
	char buff[100] = {0};
	char *temp;

	va_start(vl, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				buff[j] =  (char)va_arg(vl, int);
				j++;
			}
			else if (str[i] == 's')
			{
				str_arg = va_arg(vl, char*);
				strlcpy(&buff[j], str_arg, ft_strlen(str_arg) + 1);
				j += ft_strlen(str_arg);
			}
			//else if (str[i] == 'p')
			else if (str[i] == 'd')
			{
				temp = ft_itoa(va_arg(vl, int));
				strlcpy(&buff[j], temp, ft_strlen(temp) + 1);
				j += ft_strlen(temp);
			}
			else if (str[i] == 'i')
			{
				temp = ft_itoa(va_arg(vl, int));
				strlcpy(&buff[j], temp, ft_strlen(temp) + 1);
				j += ft_strlen(temp);
			}
			else if (str[i] == 'u')
			{
				temp = ft_itoa
			}
			//else if (str[i] == 'x')
			//else if (str[i] == 'X')
			else if (str[i] == '%')
			{
				buff[j] = '%';
				j++;
			}
		}
		else
		{
			buff[j] = str[i];
			j++;
		}
		i++;
	}
	va_end(vl);
	ft_putstr(buff);
	return (j);
}

int main(void)
{
	int ret;

	ret = ft_printf("buffer o%iverflow is comming %% // %d // %s // %c", 50, 22, "lezzzgo", 'd');
	printf("\nvalue of ret: %d", ret);
	return (0);
}
