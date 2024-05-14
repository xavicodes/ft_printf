/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:59:41 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/05/14 14:38:41 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

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
               i = ft_putnbr(va_arg(args,int));
          else if(format == 'u')
                  i = ft_putunsignednbr(va_arg(args,unsigned int));
         else if(format == 'x')
                 i = ft_puthexnbr(va_arg(args,unsigned int),('a'));
         else if(format == 'X')
                 i = ft_puthexnbr(va_arg(args,unsigned int),('a'));
         else if(format == 'p')
                 i = ft_printadress(va_arg(args, unsigned long long));
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
// int main()
// {
//         char *str = "12";
//         ft_printf("hello %%", 'W'); 
//          //printf("original: %%");            //WORKING
//         ft_printf("\n");
//         ft_printf("hello %c", 'C');             //WORKING
//          //printf("original: %c", 'C');
//         ft_printf("\n");
//         ft_printf("hello %s", "Hello my friend");
//          //printf("original: %s", "hello my friend");       //WORKING
//         ft_printf("\n");
//         ft_printf("hello %d", 123456789);
//          //printf("original: %d", 123456789);       //WORKING ONLY RANDOMIZE WITH BIGG NUMBERS!!
//         ft_printf("\n");
//         ft_printf("hello %i", '8'); 
//          //printf("original: %i", '8');            //WORKING 
//         ft_printf("\n");
//         ft_printf("hello %u",4294967295);
//          //printf("original: %lu", 4294967295);      //WORKING
//         ft_printf("\n");                        
//         ft_printf("hello %x", 31); 
//          //printf("original: %x", 31);            //WORKING
//         ft_printf("\n");
//         ft_printf("hello %X", 31);
//          //printf("original: %X", 31);             //almost needs the caps!
//         ft_printf("\n");
//         ft_printf("hello %p\n", &str);
//         //printf("original: %p", &str);
//         ft_printf("\n");
//         ft_printf("cspdiuxX%");
   
   
        
// } 

