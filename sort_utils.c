/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:45:10 by mmartine          #+#    #+#             */
/*   Updated: 2023/05/05 17:03:39 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_simple(t_list **stack, int num)
{
	t_list	*current;
	t_list	*add;
	int		*bnum;

	bnum = calloc(1, sizeof(int));
	*bnum = num;
	add = ft_lstnew(bnum);
	current = *stack;
	if (current)
	{
		while (current -> next)
			current = current->next;
		current -> next = add;
	}
	else
		*stack = add;
}

int	get_value(t_list **stack, int n)
{
	t_list	*curr;
	int		val;

	curr = *stack;
	val = 0;
	while (curr -> next)
	{
		if (n > *(int *)curr -> content)
			val++;
		curr = curr->next;
	}
	if (n > *(int *)curr -> content)
		val++;
	return (val);
}

t_list	**stack_simplyfier(t_list **stack)
{
	t_list	**simple;
	t_list	*i;

	simple = ft_calloc(1, sizeof(void *));
	i = *stack;
	while (i -> next)
	{
		add_simple(simple, get_value(stack, *(int *)i->content));
		i = i -> next;
	}
	add_simple(simple, get_value(stack, *(int *)i->content));
	ft_lstclear(stack, free);
	free(stack);
	return (simple);
}
