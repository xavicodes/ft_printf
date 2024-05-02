/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:59:41 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/05/02 18:00:12 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int     ft_putnbrbase(int n)
{
        write(1,&n,1);
        return (1);
}
int	ft_putchar(char c)
{
	write(1, &c, 1);
        return (1);
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
int ft_putstr(char *str)
{
        int i;

        i = 0;
        while(str[i] != '\0')
        {
                write(1,&str[i],1);
                i++;
        }
        return (i);
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
        


int ft_pick(va_list args,char format)
{
        int i;

        i = 0;
        if(format == 'c')
              i = ft_putchar(va_arg(args,int));
        else if( format == '%')
                i = ft_putchar('%');
        else if(format == 's')
                i = ft_putstr(va_arg(args,char *));     
         else if(format == 'd')
                i = ft_putnbr(va_arg(args,int));
        else if(format == 'i')
               i = ft_putnbrbase(va_arg(args,int));
          else if(format == 'u')
                  i = ft_putunsignednbr(va_arg(args,unsigned int));
         else if(format == 'x')
                 i = ft_puthexnbr(va_arg(args,unsigned int),('a'));
        // else if(format == 'X')
        //         i = ft_...();
        // else if(format = 'p')
        //         i = ft_...();
        return (i);
}
int    ft_printf(const char *str, ...)
{
        int i;
        va_list args;
        int len;

        len = 0;
        i = 0;
        va_start(args,str);
        if(!str)
                return (-1);
        while(str[i])
        {
                if(str[i] == '%')
                {
                        len += ft_pick(args,str[i+1]);
                        i++;
                }
                else
                        len += ft_putchar(str[i]);
                i++;
        }
        va_end (args);
        return (len);
}
int main()
{
        ft_printf("hello %%", 'W');             //WORKING
        ft_printf("\n");
        ft_printf("hello %c", 'C');             //WORKING
        ft_printf("\n");
        ft_printf("hello %s", "friend");        //WORKING
        ft_printf("\n");
        ft_printf("hello %d", 123456789);       //WORKING ONLY RANDOMIZE WITH BIGG NUMBERS!!
        ft_printf("\n");
        ft_printf("hello %i", '8');             //WORKING 
        ft_printf("\n");
        ft_printf("hello %u",4294967295);       //WORKING
        ft_printf("\n");                        
        ft_printf("hello %x", '1234');
        //ft_printf("\n");
        //ft_printf("hello %X", 'a');
        //ft_printf("\n");
        //ft_printf("hello %p", 'a');
        
}
