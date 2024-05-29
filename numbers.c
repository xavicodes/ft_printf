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
size_t  ft_putnbr_unsigned(unsigned int n)
{
	size_t len;

	len = ft_dividenbrbase(n, 10);
	if(n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		n = n % 10;
	}
	if(n < 10)
	{
		n = n + '0';
		write(1, &n, 1);
	}
	return (len);
}

int	ft_putnbrbase(unsigned int n, char *format)
{
	int	basedlen;

	basedlen = ft_dividenbrbase(n, 16);
	if (n >= 16)
	{
		ft_putnbrbase(n / 16, format);
	}
		ft_putchar(format[n % 16]);
	return (basedlen);
}
int	ft_putnbrbasep(unsigned long long n, char *format)
{
	int	i;

	i = 0;
	if (n < 16)
	{
		i = ft_putchar(format[n]);
	}
	else
	{
		 i = ft_putnbrbasep(n / 16, format);
		return (i + ft_putnbrbasep(n % 16, format));
	}
	return(i);
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
