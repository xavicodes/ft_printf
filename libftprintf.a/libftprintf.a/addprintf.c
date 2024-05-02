/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:34:50 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/05/02 18:00:12 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>

int     ft_putnbrbase(int n)
{
        write(1,&n,1);
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
int ft_puthexnbr(int n,int format)
{
        size_t len;

        len = ft_dividenbr(n);

        while(n/16)
        {
                ft_puthexnbr(n/16,format);
                n = n%16;
        }
        if(n <= '9')
                n = n +'0';
        else
                n = n + format - 10;
        write(1,&n,1);
        return (len);
        
}