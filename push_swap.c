/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:12:52 by mmartine          #+#    #+#             */
/*   Updated: 2023/04/30 18:48:48 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fillstack(char **arg, int len, t_list **stack_a)
{
	int		i;
	int		j;
	char	**matrix;

	j = 0;
	i = 0;
	while (++i < len)
	{
		matrix = ft_split(arg[i], ' ');
		while (matrix[j])
		{
			if (!validnum(matrix[j]) || !max_min_int(matrix[j]))
				return (0);
			if (!add_num_to_stack(stack_a, ft_atoi(matrix[j])))
				return (0);
			j++;
		}
		j = 0;
		free(matrix);
	}
	if (is_sort(stack_a))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc == 1)
		return (0);
	stack_a = ft_calloc(1, sizeof(void *));
	stack_b = ft_calloc(1, sizeof(void *));
	if (!fillstack(argv, argc, stack_a))
	{
		wipe_stacks(stack_a, stack_b);
		write(1, "Error\n", 6);
		return (2);
	}
	//stack_a = stack_simplyfier(stack_a);
	/*if (ft_lstsize(*stack_a) == 3)
		three_sort(*stack_a);
	else if (ft_lstsize(*stack_a) <= 5)
		five_four_sort(stack_a, stack_b);
	else
		we_sort(stack_a, stack_b);*/
	printstack(stack_a);
	wipe_stacks(stack_a, stack_b);
	//error a revisar
	return (0);
}
