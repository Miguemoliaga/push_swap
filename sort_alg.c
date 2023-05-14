/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:40:40 by mmartine          #+#    #+#             */
/*   Updated: 2023/05/14 19:32:13 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_num(t_list	**stack, int n)
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

void	step_one(t_list **stack_a, t_list **stack_b, int chunksize, int max)
{
	t_list	*curr;
	int		it;

	it = 0;
	curr = *stack_a;
	while (it < max)
	{
		if (*(int *)curr->content < chunksize)
		{
			push_b(stack_a, stack_b);
			it++;
		}
		else
			rot_a(stack_a);

	}
}

void	sort_algorithm(t_list **stack_a, t_list **stack_b,
		int stacksize, int chunksize)
{
	int	moves;
	int	num;

	num = 0;
	moves = 0;
	step_one(stack_a, stack_b, chunksize, stacksize);

	return ;
}
