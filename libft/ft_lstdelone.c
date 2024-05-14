/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:34:25 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/04/29 17:04:12 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
        if(!lst || !del)
                return (NULL);
        if(lst)
        {
                del(lst->content);
                free(lst);
        }
}