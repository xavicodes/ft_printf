#include "ft_printf.h"

char	*ft_putunsignednbr(unsigned int n)
{
	char			*strnum;
	unsigned int	numb;
	int				digits;

	digits = ft_dividenbrbase(n, 10); 
	numb = (unsigned int)n;
	strnum = malloc(sizeof(char) * (digits + 1));
	if (!strnum)
		return (0);
	strnum[digits] = '\0';
	while (digits > 0)
	{
		strnum[digits - 1] = numb % 10 + '0';
		numb /= 10;
		digits--;
	}
	return (strnum);
}

int	ft_putnbr(int n)
{
	size_t	len;
	char	*str;

	str = ft_itoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	ft_putnbrbase(unsigned int n, char *format)
{
	size_t	basedlen;

	basedlen = ft_dividenbrbase(n, 16);
	if (n >= 16)
	{
		ft_putnbrbase(n = n / 16, format);
		ft_putchar(format[n % 16]);
	}
	return (basedlen);
}

int	ft_uint(unsigned int nbr)
{
	char	*str;
	int		len;

	str = ft_putunsignednbr(nbr);
	len = ft_putstr(str);
	free(str);
	return (len);
}
