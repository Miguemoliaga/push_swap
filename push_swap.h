/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <mmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:14:50 by mmartine          #+#    #+#             */
/*   Updated: 2023/04/12 17:14:42 by mmartine         ###   ########.fr       */
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
#endif