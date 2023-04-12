/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:12:52 by mmartine          #+#    #+#             */
/*   Updated: 2023/04/12 19:18:11 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((i == 0 && (str[i] == 43 || str[i] == 45))
			|| (str[i] > 47 && str[i] < 58))
			i++;
		else
		{
			printf("el caracter: %i, en la posicion %i, no es válido\n", str[i], i);
			return (0);
		}
	}
	printf("numvalido\n");
	return (1);
}

int	fillstack(char **arg, int len, t_list **stack_a)
{
	int		i;
	int		j;
	int		num;
	char	**matrix;

	j = 0;
	i = 0;
	while (++i < len)
	{
		printf("spliteando con i = %i y len = %i\n", i, len);
		matrix = ft_split(arg[i], ' ');
		while (matrix[j])
		{
			if (!validnum(matrix[j]))
				return (0);
			printf("num valido\n");
			num = ft_atoi(matrix[j]);
			printf("postatoi\n");
			if (!add_num_to_stack(stack_a, num))
				return (0);
			j++;
		}
		free(matrix);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc == 1)
		return (0);
	stack_a = malloc(sizeof(void *));
	stack_b = malloc(sizeof(void *));
	if (!fillstack(argv, argc, stack_a))
	{
		wipe_stacks(stack_a, stack_b);
		return (0);
	}
	printstack(stack_a);
	wipe_stacks(stack_a, stack_b);
	//error a revisar
	return (0);
}
