/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_num_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:02:57 by mmartine          #+#    #+#             */
/*   Updated: 2023/04/25 16:29:26 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_list **stack_a)
{
	t_list	*curr;

	curr = *stack_a;
	if (*(int *)curr->content > *(int *)curr->next->content
		&& *(int *)curr->content < *(int *)curr->next->next->content)
		swap_a(stack_a);
	else if (*(int *)curr->content > *(int *)curr->next->content
		&& *(int *)curr->next->content > *(int *)curr->next->next->content)
	{
		swap_a(stack_a);
		reverse_a(stack_a);
	}
	else if (*(int *)curr->content > *(int *)curr->next->next->content
		&& *(int *)curr->next->content < *(int *)curr->next->next->content)
		rot_a(stack_a);
	else if (*(int *)curr->content < *(int *)curr->next->next->content
		&& *(int *)curr->next->content > *(int *)curr->next->next->content)
	{
		swap_a(stack_a);
		rot_a(stack_a);
	}
	else if (*(int *)curr->content > *(int *)curr->next->next->content
		&& *(int *)curr->content < *(int *)curr->next->content)
		reverse_a(stack_a);
}
