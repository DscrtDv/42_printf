#include "ft_printf.h"
#include "libft/libft.h"

int	handle_char(char c)
{
	ft_putchar(c);
	return (1);
}

int handle_str(char *str)
{
	ft_putstr(str);
	return ((int) ft_strlen(str));
}

int	handle_int(int n)
{
	char	*str_itoa;
	int		len;
	str_itoa = ft_itoa(n);
	ft_putstr(str_itoa);
	len = (int) ft_strlen(str_itoa);
	free(str_itoa);
	return (len);
}

int	handle_hex(void *ptr, char c)
{
	unsigned long	n;
	char			*result;
	int				len;
	
	len = 0;
	n = (unsigned long) ptr;
	if (c == 'p')
	{
		if (!n)
			return (handle_str("0x0"));
		len += handle_str("0x");
		result = hex_converter(n, "0123456789abcdef");
	}
	if (!n)
		return (handle_char('0'));
	else if (c == 'x')
		result = hex_converter(n, "0123456789abcdef");
	else if (c == 'X')
		result = hex_converter(n, "0123456789ABCDEF");
	len += handle_str(result);
	free(result);
	return (len);
}

int	handle_percent()
{
	ft_putchar('%');
	return (1);
}


