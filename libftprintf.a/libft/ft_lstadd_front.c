/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:09:45 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/04/29 16:12:09 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


void ft_lstadd_front(t_list **lst, t_list *new)
{
        if(!lst)
                return;
        if(*lst)
        {
                new->next = *lst;
                *lst = new;
        }
}
