/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 07:28:54 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/07/28 10:24:35 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALLOC_H
# define FT_ALLOC_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

enum					e_address_state
{
	MALLOC,
	CALLOC,
	REALLOC,
	FREE_ALL,
	FREE_PTR,
};

typedef struct s_address
{
	void				*address;
	size_t				size;
	struct s_address	*next;
	struct s_address	*prev;
}						t_address;

void					*ft_alloc(size_t size, void *ptr,char c);

#endif