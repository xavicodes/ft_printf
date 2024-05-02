/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:23:26 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/04/29 16:34:00 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
        t_list *last;
        
        if(!lst)
                return (NULL);
        if(*lst)
        {       
                last = ft_lstlast(*lst);
                last->next = new;
        }
        else
                *lst = new;
}