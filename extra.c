#include "ft_printf.h"

int ft_printadress(long n, char *format)
{
        if((void *)n == NULL)
                return(ft_putstr("(nil)"));
        write(1,"0x",2);
        return ft_putnbrbase(n,format);
}

int ft_dividenbr(int d)
{
        int i;

        i = 0;
        while(d/10)
        {
                i++;
                d = d/10;
        }
        return(i);
}

int ft_dividenbrbase(int n, int base)
{
        int i;

        i = 0;

        while(n/base)
        {
                i++;
                n = n/base;
        }
        return(i);
}