#include "ft_printf.h"

int ft_printadress(void *n, char *format)
{
        int i;

        i = 0;
        if(n == NULL)
                return(ft_putstr("(nil)"));
        write(1,"0x",2);
        i = 2;
        if((unsigned long long) n == 0)
        {
                write(1,"0",1);
                return (3);
        }
        return (i += ft_putnbrbasep((unsigned long long)n,format));
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

int ft_dividenbrbase(long long int n, int base)
{
        int i;

        i = 0;
        if(n == 0)
                return 1;
        while(n/base) 
        {
                i++;
                n = n/base;
        }
        i++;
        return(i);
}