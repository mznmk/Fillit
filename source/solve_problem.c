/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_problem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:08:50 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/16 00:01:14 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static void	calculate_start_grid_size(t_vars *v)
{
	int		block_total_count;
	int		grid_size;

	block_total_count = ft_lstsize(v->ttrmns) * TM_BLOCK_COUNT;
	grid_size = 0;
	while (grid_size * grid_size < block_total_count)
		grid_size++;
	v->grid_size = grid_size;
}

/*!
** @brief	solve problem
** @param	v	fillit variables (structure)
** @return	none
*/
void	solve_problem(t_vars *v)
{
	bool	try_solve_status;

	try_solve_status = false;
	calculate_start_grid_size(v);
	while (!try_solve_status)
	{
		create_grid(v);
		try_solve_status = try_solve_problem(v->grid, v->grid_size, v->ttrmns);
		if (!try_solve_status)
		{
			free_grid(v);
			v->grid_size++;
		}
	}
	print_success_message(SUCCESS_MSG_HEADER SUCCESS_SOLVE_PROBLEM);
}
