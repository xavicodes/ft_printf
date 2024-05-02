/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:05:10 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/04/29 17:11:52 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
        t_list *temp;

        if(!lst || !*lst || !del)
                return;
        while(*lst)
        {
                temp = (*lst)->next;
                ft_lstdelone(lst,del);
                *lst = temp;
        }
}