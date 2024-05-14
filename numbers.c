#include "ft_printf.h"

int     ft_putnbrbase(int n)
{
        write(1,&n,1);
        return (1);
}
//-------
int ft_putunsignednbr(unsigned int n)
{	
        unsigned int	digit;

	digit = 0;
	
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else if (n >= 10)
	{
		ft_putunsignednbr((n / 10));
		digit = (n % 10) + '0';
		ft_putchar(digit);
	}
        return(ft_dividenbr(n));

}

int	ft_putnbr(int n)
{
	int	digit;

	digit = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 12);
			return(ft_dividenbr(n));
		}
		write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else if (n >= 10)
	{
		ft_putnbr((n / 10));
		digit = (n % 10) + '0';
		ft_putchar(digit);
	}
        return(ft_dividenbr(n));
}
int ft_puthexnbr(long long n,int format)
{
        size_t len;

        len = ft_dividenbr(n);

        while(n/16)
        {
                ft_puthexnbr(n/16,format);
                n = n%16;
        }
        if(n <= 9)
                n = n +'0';
        else
                n = n + format - 10;
        write(1,&n,1);
        
        return (len);
        
}
int ft_putadress(unsigned long long       n)
{
        if(!n)
                return (ft_putstr("(nill)"));
        size_t len;

        len = ft_dividenbr(n);

        while(n/16)
        {
                ft_putadress(n/16);
                n = n%16;
        }
        if(n <= 9)
                n = n +'0';
        else
                n = n + 'a' - 10;
        write(1,&n,1);

return(len+2);
}


