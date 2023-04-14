/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:03:47 by mmartine          #+#    #+#             */
/*   Updated: 2023/04/14 18:22:40 by mmartine         ###   ########.fr       */
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

	bnum = calloc(1, sizeof(int));
	*bnum = num;
	add = ft_lstnew(bnum);
	current = *stack;
	if (current)
	{
		while (current->next)
		{
			if (*(int *)(current -> content) == num)
				return (0);
			current = current->next;
		}
		current -> next = add;
	}
	else
		*stack = add;
	return (1);
}

int	max_min_int(char *str)
{
	int				mult;
	unsigned int	resul;
	int				i;

	i = 0;
	mult = 1;
	resul = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		resul = (resul * 10 + (str[i] - '0'));
		if ((resul > 2147483647 && mult == 1)
			|| (resul > 2147483648 && mult == -1))
		{
			printf("maxint or minint\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	validnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 43 || str[i] == 45)
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] > 47 && str[i] < 58)
			i++;
		else
			return (0);
	}
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
