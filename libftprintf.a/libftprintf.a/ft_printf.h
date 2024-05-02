
#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
//#include 

int     ft_putnbrbase(int n);

int ft_dividenbr(int d);

int ft_putstr(char *str);

int ft_putunsignednbr(unsigned int n);

int	ft_putnbr(int n);

int ft_pick(va_list args,char format);

int    ft_printf(const char *str, ...);

#endif


