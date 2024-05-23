/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlourenc <xlourenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:59:41 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/05/23 13:15:40 by xlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
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
                i = ft_uint(va_arg(args, unsigned int));
          else if(format == 'x')
                i = ft_putnbrbase(va_arg(args,unsigned int), ("0123456789abcdef"));
         else if(format == 'X')
                i = ft_putnbrbase(va_arg(args,unsigned int),("0123456789ABCDEF")); 
         else if(format == 'p')
                i = ft_printadress(va_arg(args, long),("0123456789abcdef"));
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
/* int main()
{
        char *str = "12";
        ft_printf("hello %%", 'W'); 
         //printf("original: %%");            //WORKING
        ft_printf("\n");
        ft_printf("hello %c", 'C');             //WORKING
         //printf("original: %c", 'C');
        ft_printf("\n");
        ft_printf("hello %s", "Hello my friend");
         //printf("original: %s", "hello my friend");       //WORKING
        ft_printf("\n");
        ft_printf("hello %d", 123456789);
         //printf("original: %d", 123456789);       //WORKING ONLY RANDOMIZE WITH BIGG NUMBERS!!
        ft_printf("\n");
        ft_printf("hello %i", '8'); 
         //printf("original: %i", '8');            //WORKING 
        ft_printf("\n");
        ft_printf("hello %u",4294967295);
         //printf("original: %lu", 4294967295);      //WORKING
        ft_printf("\n");                        
        ft_printf("hello %x", 31); 
         //printf("original: %x", 31);            //WORKING
        ft_printf("\n");
        ft_printf("hello %X", 31);
         //printf("original: %X", 31);             //almost needs the caps!
        ft_printf("\n");
        ft_printf("hello %p\n", &str);
        //printf("original: %p", &str);
        ft_printf("\n");
        ft_printf("cspdiuxX%");        
}  */

/*    int	main(void)
{
	ft_printf("%d \n", ft_printf("ola%%%"));
	//printf("%d \n", printf("ola%%%"));
 
	int teste = printf("hello world\n");
	printf("imprimiu: %d\n", teste);
	int teste2 = ft_printf("hello world\n");
	ft_printf("imprimiu: %d\n", teste2);
	printf("\n");
	//int x = 42;
	int x2 = 34;
	void *ptrx2 = &x2;
	//void *ptr = &x;

	
	ft_printf("Hello\n");
	ft_printf("%d \n", ft_printf(""));
	ft_printf("%d \n", ft_printf(NULL));
	ft_printf("CHARACTERS: %c %c\n", 'a', 'b');
	ft_printf("STRINGS: %s %s\n", "Good", "bye");
	ft_printf("DECIMAL: %i %d\n", 42, 123);
	ft_printf ("DECIMALS: %d %d\n", 1977, 650000L);
	ft_printf("POINTER NULO: %p \n", NULL ); //esta mal
	ft_printf("POINTER é: %p\n", (void*)1000000);
	ft_printf("POINTER 0: %p %p \n", (void *)0, (void *)0); //esta mal
	ft_printf ("DECIMAL e HEXADECIMAL: %d %x %X \n", 255, 255, 255);
	ft_printf ("HEXADECIMAL 0: %x %X\n", 0, 0);
	ft_printf ("Unsigned int: %u %u\n",  2147483647, UINT_MAX);
	ft_printf ("Unsigned int: %u \n", UINT_MAX);
 	ft_printf ("Mix: %c, %s, %p, %d, %i, %x, %X, %u, %%, all mixed\n", 'A',
		"Mix", ptrx2, 34, 34, 255, 255, UINT_MAX);


	ft_printf("\n");
	
	printf("Hello\n");
	printf("%d \n", printf(""));
	printf("%d \n", printf(NULL));
	printf("Characters: %c %c\n", 'a', 'b');
	printf("Strings: %s %s\n", "Good", "bye");
	printf("Decimal: %d %d\n", 42, 123);
	printf ("Decimals: %d %ld\n", 1977, 650000L);
	printf("Pointer nulo: %p \n", NULL );
	printf("Pointer de x é: %p\n", (void*)1000000);
	printf("Pointer 0: %p %p \n", (void *)0, (void *)0);
	printf ("Decimal e hexadecimal: %d %x %X \n", 255, 255, 255);
	printf (" Hexadecimal 0: %x %X\n", 0, 0);
	printf ("Unsigned int: %u %u\n", 2147483647, UINT_MAX);
	printf ("Unsigned int: %u \n", UINT_MAX);
	printf ("Mix: %c, %s, %p, %d, %i, %x, %X, %u, %%, all mixed\n", 'A', "Mix",
		ptrx2, 34, 34, 255, 255, UINT_MAX);
	return (0);
}  */ 
