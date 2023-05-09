/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_num_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:16:33 by mmartine          #+#    #+#             */
/*   Updated: 2023/05/09 16:39:08 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_high_num(t_list	**stack, int n)
{
	int		pos;
	t_list	*curr;

	pos = 0;
	curr = *stack;
	while (*(int *)curr->content != n)
	{
		pos++;
		curr = curr -> next;
	}	
	return (pos++);
}

void	five_four_sort(t_list **stack_a, t_list **stack_b)
{
	int	times;
	int	rolls;

	times = ft_lstsize(*stack_a) - 3;
	while (times-- > 0)
	{
		rolls = search_high_num(stack_a, ft_lstsize(*stack_a) - 1);
		if (rolls > ft_lstsize(*stack_a) / 2)
		{
			rolls = ft_lstsize(*stack_a) - rolls;
			while (rolls-- > 0)
				reverse_a(stack_a);
		}
		else
			while (rolls-- > 0)
				rot_a(stack_a);
		push_b(stack_a, stack_b);
	}
	three_sort(stack_a);
	times = ft_lstsize(*stack_b);
	while (times-- > 0)
	{
		push_a(stack_a, stack_b);
		rot_a(stack_a);
	}
}
