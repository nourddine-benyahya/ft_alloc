/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 07:28:38 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/07/28 11:06:30 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloc.h"

void	*clear_address(t_address **lst)
{
	t_address	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->address);
		free(tmp);
	}
	return (NULL);
}

void	add_back(t_address **lst, t_address *new_node)
{
	t_address	*tmp;

	tmp = (*lst);
	if (!lst)
		return ;
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

t_address	*new_node(void *ptr, size_t size)
{
	t_address	*node;

	node = malloc(sizeof(t_address));
	if (!node)
		return (NULL);
	node->address = ptr;
	node->size = size;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	*ft_malloc(size_t size, t_address **lst)
{
	void		*ptr;
	t_address	*newnode;

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
	return (ptr);
}

static void	*ft_calloc( size_t size, t_address **lst)
{
	void				*ptr;
	t_address           *newnode;
    size_t               i;

    i = 0;
	if (size > SIZE_MAX)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	while (i < size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
    newnode = new_node(ptr, size);
	if (!newnode)
	{
		free(ptr);
		return (NULL);
	}
	add_back(lst, newnode);
	return (ptr);
}

void *ft_free(void *ptr, t_address **lst)
{
    t_address *current;
    // t_address *next;
    // t_address *prev;

    if (!ptr || !lst || !*lst)
        return (NULL);
    current = *lst;
    while (current)
    {
        if (ptr == current->address)
        {
            if (current->prev)
                current->prev->next = current->next;
            else
                *lst = current->next;

            if (current->next)
                current->next->prev = current->prev;
            free(current->address);
            free(current);
            return (NULL);
        }
        current = current->next;
    }
    return (NULL); 
}


void	*ft_alloc(size_t size, void *ptr,char c)
{
	static t_address	*address_list = NULL;

	if (c == MALLOC)
		return (ft_malloc(size, &address_list));
    else if (c == CALLOC)
        return (ft_calloc(size, &address_list));
    else if (c == FREE_ALL)
        return (ft_free(ptr, &address_list));
	else if (c == FREE_ALL)
		return (clear_address(&address_list));
    
	return (NULL);
}
