/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:00:29 by mmartine          #+#    #+#             */
/*   Updated: 2023/04/03 21:09:03 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_list **stack)
{
	t_list	*head;

	head = ft_lstlast(stack);
	head -> next = *stack;
	*stack = head;
}

//tenog que mirar lo que hay que poner en NULL para los -> next y terminar eso.
