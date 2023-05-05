/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:22:41 by mmartine          #+#    #+#             */
/*   Updated: 2023/05/05 17:05:50 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*aux1;
	t_list	*aux2;

	aux1 = (*stack)-> next;
	aux2 = *stack;
	aux2 -> next = aux1 -> next;
	aux1 -> next = aux2;
	*stack = aux1;
}

void	swap_a(t_list **stack)
{
	if (!((*stack)-> next))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	swap(stack);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **stack)
{
	if (!((*stack)-> next))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	swap(stack);
	write(1, "sb\n", 3);
}

void	swap_ab(t_list **stacka, t_list **stackb)
{
	if (!((*stacka)-> next) || !((*stackb)-> next))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	swap(stacka);
	swap(stackb);
	write(1, "ss\n", 3);
}
