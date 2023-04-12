/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:03:47 by mmartine          #+#    #+#             */
/*   Updated: 2023/04/12 19:20:44 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wipe_stacks(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a, free);
	free(stack_a);
	ft_lstclear(stack_b, free);
	free(stack_b);
}

int	add_num_to_stack(t_list **stack, int num)
{
	t_list	*current;
	t_list	*add;
	int		*bnum;

	bnum = malloc(sizeof(int));
	*bnum = num;
	add = ft_lstnew(bnum);
	printf("hola hla\n");
	current = *stack;
	if (current)
	{
		while (current->next)
		{
			if (*(int *)(current -> content) == num)
			{
				printf("caracter repetido\n");
				return (0);
			}
			printf("rellenando\n");
			*(int *)current -> content = num;
			current = current->next;
		}
		current -> next = add;
	}
	else
		*stack = add;
	return (1);
}

//quitar de aqui al final y del .h
void	printstack(t_list **stack)
{
	t_list	*current;

	current = *stack;
	if (current)
	{
		while (current -> next)
		{
			printf("%i ", *(int *)current -> content);
			current = current -> next;
		}
		printf("%i\n", *(int *)current -> content);
	}
	else
		printf("stack vacio");
}
