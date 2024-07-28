/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 09:52:22 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/07/28 10:16:24 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloc.h"
#include <stdlib.h>

void	leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	atexit(leaks);
	ft_alloc(sizeof(char *), MALLOC);
	ft_alloc(sizeof(int *), CALLOC);
	ft_alloc(sizeof(t_address *), MALLOC);
	ft_alloc(0, FREE_ALL);
	return (0);
}
