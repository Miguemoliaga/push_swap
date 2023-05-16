/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_num_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:16:33 by mmartine          #+#    #+#             */
/*   Updated: 2023/05/16 17:24:52 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_four_sort(t_list **stack_a, t_list **stack_b)
{
	int	times;
	int	rolls;

	times = ft_lstsize(*stack_a) - 3;
	while (times-- > 0)
	{
		rolls = search_num(stack_a, ft_lstsize(*stack_a) - 1);
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
