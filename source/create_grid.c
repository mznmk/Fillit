/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:56:59 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/15 23:57:12 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*!
** @brief	free grid to store solution
** @param	v	fillit variables (structure)
** @return	none
*/
void 	free_grid(t_vars *v)
{
	int		i;

	if (!v->grid)
		return ;
	i = -1;
	while (++i < v->grid_size)
	{
		if (v->grid[i])
			ft_memdel((void **)&v->grid[i]);
	}
	ft_memdel((void **)&v->grid);
}

/*!
** @brief	create grid to store solution
** @param	v	fillit variables (structure)
** @return	none
*/
void	create_grid(t_vars *v)
{
	char	**grid;
	char	*line;
	int		i;

	v->grid = NULL;
	grid = (char **)ft_memalloc(sizeof(char *) * v->grid_size);
	if (!grid)
		exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_ALLOCATE_MEMORY, false);
	v->grid = grid;
	i = -1;
	while (++i < v->grid_size)
		grid[i] = NULL;
	i = -1;
	while (++i < v->grid_size)
	{
		line = (char *)ft_memalloc(sizeof(char) * v->grid_size);
		if (!line)
			exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_ALLOCATE_MEMORY, false);
		grid[i] = line;
		ft_memset(grid[i], C_SPACE, v->grid_size);
	}
}
