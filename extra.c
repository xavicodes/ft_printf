#include "ft_printf.h"

int ft_printadress(unsigned long long n)
{
        if((void *)n == NULL)
                return(ft_putstr("(nil)"));
        write(1,"0x",2);
        return ft_putadress(n);
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