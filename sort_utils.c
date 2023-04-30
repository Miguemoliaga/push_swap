/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:45:10 by mmartine          #+#    #+#             */
/*   Updated: 2023/04/30 20:11:15 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
t_list	**stack_simplyfier(t_list **stack)
{
	t_list	**nstack;
	t_list	*oldcurr;
	t_list	*nscurr;
	t_list	*add;
	int		num;

	oldcurr = *stack;
	nstack = ft_calloc(1, sizeof(void *));
	while (oldcurr)
	{
		num = 0;
		nscurr = *nstack;
		while (nscurr)
		{
			if (num > *(int *)nscurr->content)
				num++;
			else
				*(int *)nscurr->content += 1;
			nscurr = nscurr->next;
		}
		*(int *)add->content = num;
		ft_lstadd_back(nstack, add);
		oldcurr = oldcurr->next;
	}
	ft_lstclear(stack, free);
	free(stack);
	return (nstack);
}
*/

t_list	**stack_simplyfier(t_list **stack)
{
	t_list	**simple;
	t_list	*i;
	t_list	*add;
	int		*bnum;

	bnum = calloc(1, sizeof(int));
	add = ft_lstnew(bnum);
	i = *stack;
	simple = ft_calloc(1, sizeof(void *));
	while (i -> next)
	{

	}
	ft_lstclear(stack, free);
	free(stack);
	return (simple);
}
