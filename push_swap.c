/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:12:52 by mmartine          #+#    #+#             */
/*   Updated: 2023/06/20 19:37:17 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stackselector(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) > 200)
		return (50);
	else
		return ((ft_lstsize(*stack_a) / 25) + 22);
}

int	freematrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	return (0);
}

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
				return (freematrix(matrix));
			if (!add_num_to_stack(stack_a, ft_atoi(matrix[j])))
				return (freematrix(matrix));
			j++;
		}
		j = 0;
		freematrix(matrix);
	}
	if (ft_lstsize(*stack_a) <= 2)
		return (0);
	if (is_sort(stack_a))
		return (0);
	return (1);
}

void	show_leaks(void)
{
	system("leaks push_swap");
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
		write(2, "Error\n", 6);
		return (2);
	}
	stack_a = stack_simplyfier(stack_a);
	if (ft_lstsize(*stack_a) == 3)
		three_sort(stack_a);
	else if (ft_lstsize(*stack_a) <= 5)
		five_four_sort(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) > 5)
		sort_algorithm(stack_a, stack_b, ft_lstsize(*stack_a),
			stackselector(stack_a));
	if (ft_lstsize(*stack_b) == 1)
		push_a(stack_a, stack_b);
	wipe_stacks(stack_a, stack_b);
	return (0);
}
