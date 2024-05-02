/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:34:50 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/05/02 11:41:22 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>

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