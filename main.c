/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 09:52:22 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/07/28 11:07:22 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloc.h"
#include <stdlib.h>

void	leaks(void)
{
	system("leaks a.out");
}

int	ft_main(void)
{
	atexit(leaks);
	ft_alloc(sizeof(char *), NULL, MALLOC);
	void *ptr = ft_alloc(sizeof(int *), NULL, CALLOC);
	ft_alloc(sizeof(t_address *), ptr, FREE_PTR);
	ft_alloc(0, NULL, FREE_ALL);
	return (0);
}
int main()
{
    ft_main();
}
