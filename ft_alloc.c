/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 07:28:38 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/07/28 09:54:20 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "ft_alloc.h"



void *clear_address(t_address **lst)
{
    t_address *tmp;

    while (*lst)
    {
        tmp = *lst;
        *lst = (*lst)->next;
        free(tmp->address);
        free(tmp);
    }
    return (NULL);
}

void add_back(t_address **lst, t_address *new_node)
{
    t_address *tmp;

    tmp =  (*lst);
    if (!lst)
        return;
    if (!(*lst))
        *lst = new_node;
    else
    {
        tmp = *lst;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_node;
        new_node->prev = tmp;
    }
}

t_address *new_node(void *ptr, size_t size)
{
    t_address *node;

    node = malloc(sizeof(t_address));
    if (!node)
        return (NULL);
    node->address = ptr;
    node->size = size;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

void *ft_malloc(size_t size, t_address **lst)
{
    void *ptr;
    t_address *newnode;

    ptr = malloc(size);
    if (!ptr)
        return (NULL);
    newnode = new_node(ptr, size);
    if (!newnode)
    {
        free(ptr);
        return (NULL);
    }
    add_back(lst, newnode);
    return ptr;
}

void *ft_alloc(size_t size, char c)
{
    static t_address *address_list = NULL;

    if (c == MALLOC)
        return ft_malloc(size, &address_list);
    if (c == FREE_ALL)
        return clear_address(&address_list);
    return NULL;
}


