/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:12:52 by mmartine          #+#    #+#             */
/*   Updated: 2023/04/11 18:19:14 by mmartine         ###   ########.fr       */
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
			return (0);
	}
	return (1);
}

	//num puede que no sea necesario
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
		matrix = ft_split(arg[j], ' ');
		while (matrix[j])
		{
			if (!validnum(matrix[j]))
				return (0);
			//num va dentro de las listas
			num = ft_atoi(matrix[j]);
			//aqui se añade el numero a lo que te cuento
			j++;
		}
		free(matrix);
		i++;
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
	if (!fillstack(argv, argc, stack_a))
		return (0);
		//error a revisar
	return (0);
}
