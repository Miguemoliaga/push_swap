/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:14:50 by mmartine          #+#    #+#             */
/*   Updated: 2023/08/01 19:48:54 by mmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void	wipe_stacks(t_list **stack_a, t_list **stack_b);
int		add_num_to_stack(t_list **stack, int num);
void	printstack(t_list **stack);
int		validnum(char *str);
int		max_min_int(char *str);
void	swap_a(t_list **stack);
void	swap_b(t_list **stack);
void	swap_ab(t_list **stacka, t_list **stackb);
void	reverse_a(t_list **stack_a);
void	reverse_b(t_list **stack_b);
void	reverse_ab(t_list **stack_a, t_list **stack_b);
void	rot_a(t_list **stack_a);
void	rot_b(t_list **stack_b);
void	rot_ab(t_list **stack_a, t_list **stack_b);
void	three_sort(t_list **stack_a);
int		is_sort(t_list **stack);
t_list	**stack_simplyfier(t_list **stack);
void	five_four_sort(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	sort_algorithm(t_list **stack_a, t_list **stack_b,
			int stacksize, int chunksize);
int		search_num(t_list **stack, int n);
void	step_one(t_list **stack_a, t_list **stack_b, int chunksize, int max);
void	show_leaks(void);

#endif