/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_solve_problem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:01:59 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/16 00:24:02 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static bool	check_can_set_in_grid(t_ttrmn *ttrmn, int grid_size, char x_or_y)
{
	int		i;
	int		x_y[TM_BLOCK_COUNT];

	i = -1;
	while (++i < TM_BLOCK_COUNT)
	{
		if (x_or_y == 'x')
			x_y[i] = ttrmn->coord[i].x + ttrmn->offset.x;
		else if (x_or_y == 'y')
			x_y[i] = ttrmn->coord[i].y + ttrmn->offset.y;
		else
			return (false);
	}
	i = -1;
	while (++i < TM_BLOCK_COUNT)
	{
		if (x_y[i] < 0 || grid_size - 1 < x_y[i])
			return (false);
	}
	return (true);
}

static bool	check_can_set_without_overlap(char **grid, t_ttrmn *ttrmn)
{
	int		i;
	int		x[TM_BLOCK_COUNT];
	int		y[TM_BLOCK_COUNT];

	i = -1;
	while (++i < TM_BLOCK_COUNT)
	{
		x[i] = ttrmn->coord[i].x + ttrmn->offset.x;
		y[i] = ttrmn->coord[i].y + ttrmn->offset.y;
	}
	i = -1;
	while (++i < TM_BLOCK_COUNT)
	{
		if (grid[y[i]][x[i]] != C_SPACE)
			return (false);
	}
	return (true);
}

static void	set_tetrimino(char **grid, t_ttrmn *ttrmn, char print_letter)
{
	int		i;
	int		x[TM_BLOCK_COUNT];
	int		y[TM_BLOCK_COUNT];

	i = -1;
	while (++i < TM_BLOCK_COUNT)
	{
		x[i] = ttrmn->coord[i].x + ttrmn->offset.x;
		y[i] = ttrmn->coord[i].y + ttrmn->offset.y;
	}
	i = -1;
	while (++i < TM_BLOCK_COUNT)
		grid[y[i]][x[i]] = print_letter;
}

/*!
** @brief	try solve problem (recursive)
** @param	grid		grid to store solution
** @param	grid_size	size of grid (square)
** @param	ttrmns		contain all tetrimino
** @return	result to solve problem (true / false)
*/
bool	try_solve_problem(char **grid, int grid_size, t_list *ttrmns)
{
	t_ttrmn		*ttrmn;

	if (!ttrmns)
		return (true);
	ttrmn = (t_ttrmn *)ttrmns->content;
	ttrmn->offset.y = 0;
	while (check_can_set_in_grid(ttrmn, grid_size, 'y'))
	{
		ttrmn->offset.x = 0;
		while (check_can_set_in_grid(ttrmn, grid_size, 'x'))
		{
			if (check_can_set_without_overlap(grid, ttrmn))
			{
				set_tetrimino(grid, ttrmn, ttrmn->print_letter);
				if (try_solve_problem(grid, grid_size, ttrmns->next))
					return (true);
				else
					set_tetrimino(grid, ttrmn, C_SPACE);
			}
			ttrmn->offset.x++;
		}
		ttrmn->offset.y++;
	}
	return (false);
}
