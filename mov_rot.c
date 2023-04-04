/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 20:14:24 by mmartine          #+#    #+#             */
/*   Updated: 2023/04/04 16:27:26 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*last;
	t_list	*newfirst;

	last = *stack;
	newfirst = last -> next;
	ft_lstadd_back(stack, last);
	*stack = newfirst;
}

void	rot_a(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rot_b(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rot_ab(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
