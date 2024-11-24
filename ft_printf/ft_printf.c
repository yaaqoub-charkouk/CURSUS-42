#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int ret;
	va_list args;
	long arg;

	va_start(args, format);
	if (!format || write(1, 0, 0) == -1)
		return (-1);
	ret = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				ret += ft_putchar_fd(va_arg(args, int), 1);
			else if (*format == 's')
				ret += ft_putstr_fd(va_arg(args, char *), 1);
			if (*format == 'p')
			{
				ret += ft_putstr_fd("0x", 1);
				ret += ft_putnbr_base((unsigned long)va_arg(args, void *), "0123456789abcdef");
			}
			else if (*format == 'd' || *format == 'i')
			{
				arg = va_arg(args, int);
				if (arg < 0)
				{
					arg = -arg;
					ret += ft_putchar_fd('-', 1);
				}
				ret += ft_putnbr_base((unsigned long)arg, "0123456789");
			}
			else if (*format == 'u')
				ret += ft_putnbr_base((unsigned int)va_arg(args, int), "0123456789");
			else if (*format == 'x')
				ret += ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
			else if (*format == 'X')
				ret += ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
			else if (*format == '%')
				ret += ft_putchar_fd('%', 1);
		}
		else
			ret += ft_putchar_fd(*format, 1);
		format++;
	}
	return (ret);
}
