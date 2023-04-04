/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:00:29 by mmartine          #+#    #+#             */
/*   Updated: 2023/04/04 16:32:31 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_list **stack)
{
	t_list	*newhead;
	t_list	*newlast;

	newlast = *stack;
	while (newlast -> next -> next)
		newlast = newlast -> next;
	newhead = ft_lstlast(stack);
	newhead -> next = *stack;
	*stack = newhead;
	newlast -> next = NULL;
}

void	reverse_a(t_list **stack_a)
{
	reverse(stack_a);
	write(1, "rra\n", 4);
}

void	reverse_b(t_list **stack_b)
{
	reverse(stack_b);
	write(1, "rrb\n", 4);
}

void	reverse_ab(t_list **stack_a, t_list **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	write(1, "rrr\n", 4);
}
