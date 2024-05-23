#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
        return (1);
}

int ft_putstr(char *str)
{
        int i;

        i = 0;
        if (!str)
                return (ft_putstr("(null)"));
        while(str[i] != '\0')
        {
                write(1,&str[i],1);
                i++;
        }
        return (i);
}