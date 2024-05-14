
#ifndef FT_PRINTF_A
#define FT_PRINTF_A

#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

int     ft_putnbrbase(int n);

int ft_putchar(char c);

int ft_putunsignednbr(unsigned int n);

int ft_printadress(unsigned long long n);

int ft_putadress(unsigned long long n);

int ft_puthexnbr(long long n,int format);

int ft_dividenbr(int d);

int ft_putstr(char *str);

int ft_putunsignednbr(unsigned int n);

int	ft_putnbr(int n);

int ft_pick(va_list args,char format);

int    ft_printf(const char *str, ...);

#endif


