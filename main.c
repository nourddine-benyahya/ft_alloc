/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenyahy <nbenyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 09:52:22 by nbenyahy          #+#    #+#             */
/*   Updated: 2024/07/28 09:58:26 by nbenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloc.h"
#include <stdlib.h>

void leaks()
{
    system("leaks a.out");
}

int main()
{
    atexit(leaks);
    ft_alloc(sizeof(char *), MALLOC);
    ft_alloc(sizeof(int *), MALLOC);
    ft_alloc(sizeof(t_address *), MALLOC);
    ft_alloc(0, FREE_ALL);
    return 0;
}