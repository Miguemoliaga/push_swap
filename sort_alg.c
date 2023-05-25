/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:40:40 by mmartine          #+#    #+#             */
/*   Updated: 2023/05/25 13:56:30 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fromtop(t_list **stack_a, t_list **stack_b, int num, int pos)
{
	int	sp;

	sp = 0;
	while (pos-- > 0)
	{
		if (*(int *)(*stack_b)->content == num - 1)
		{
			sp = 1;
			push_a(stack_a, stack_b);
		}
		if (ft_lstsize(*stack_b) > 1)
			rot_b(stack_b);
	}
	push_a(stack_a, stack_b);
	return (sp);
}

int	frombot(t_list **stack_a, t_list **stack_b, int num, int pos)
{
	int	sp;

	sp = 0;
	while (pos-- > 0)
	{
		if (*(int *)(*stack_b)->content == num - 1)
		{
			sp = 1;
			push_a(stack_a, stack_b);
		}
		if (ft_lstsize(*stack_b) > 1)
			reverse_b(stack_b);
	}
	push_a(stack_a, stack_b);
	return (sp);
}

void	step_two(t_list **stack_a, t_list **stack_b, int max)
{
	int		it;
	int		pos;

	it = 1;
	while (it <= max)
	{
		pos = search_num(stack_b, max - it);
		if (pos > ft_lstsize(*stack_b) / 2)
		{
			if (frombot(stack_a, stack_b, max - it, ft_lstsize(*stack_b) - pos))
			{
				swap_a(stack_a);
				it++;
			}
		}
		else
		{
			if (fromtop(stack_a, stack_b, max - it, pos))
			{
				swap_a(stack_a);
				it++;
			}
			printstack(stack_a);
			printstack(stack_b);
		}
		it++;
	}
}

void	step_one(t_list **stack_a, t_list **stack_b, int chunksize, int max)
{
	t_list	*curr;
	int		it;
	int		topnum;

	it = 0;
	curr = *stack_a;
	while (it < max)
	{
		topnum = chunksize * ((it / max) + 1);
		if (*(int *)curr->content < chunksize)
		{
			push_b(stack_a, stack_b);
			it++;
		}
		else
			rot_a(stack_a);
		printstack(stack_a);
		printstack(stack_b);
	}
}

void	sort_algorithm(t_list **stack_a, t_list **stack_b,
		int stacksize, int chunksize)
{
	step_one(stack_a, stack_b, chunksize, stacksize);
	step_two(stack_a, stack_b, stacksize);
	return ;
}
