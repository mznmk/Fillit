/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:07:50 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/16 00:23:17 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static void	print_solution_horizontal_line(t_vars *v)
{
	int		i;

	i = -1;
	ft_putstr(ESC_FNT_BOLD);
	ft_putchar('+');
	while (++i < v->grid_size)
		ft_putchar('-');
	ft_putendl("+");
	ft_putstr(ESC_RESET);
}

static void	print_solution_header(t_vars *v)
{
	ft_putstr(ESC_FNT_BOLD ESC_CLR_YELLOW);
	ft_putendl("[ solution ]");
	ft_putstr(ESC_RESET);
	print_solution_horizontal_line(v);
}

static void	print_solution_footer(t_vars *v)
{
	print_solution_horizontal_line(v);
}

/*!
** @brief	print solution
** @param	v	fillit variables (structure)
** @return	none
*/
void	print_solution(t_vars *v)
{
	int		x;
	int		y;

	y = -1;
	print_solution_header(v);
	ft_putstr(ESC_FNT_BOLD);
	while (++y < v->grid_size)
	{
		x = -1;
		ft_putchar('|');
		while (++x < v->grid_size)
		{
			ft_putchar(v->grid[y][x]);
		}
		ft_putendl("|");
	}
	ft_putstr(ESC_RESET);
	print_solution_footer(v);
}
