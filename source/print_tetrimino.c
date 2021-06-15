/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 02:44:04 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/16 00:14:00 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static void	print_tetrimino_horizontal_line(void)
{
	ft_putendl("+----+");
}

static void	print_tetrimino_header(t_ttrmn *tetrimino)
{
	ft_putstr(ESC_FNT_BOLD ESC_CLR_YELLOW);
	ft_putstr("[");
	ft_putchar(tetrimino->print_letter);
	ft_putendl("]");
	ft_putstr(ESC_RESET);
	print_tetrimino_horizontal_line();
}

static void	print_tetrimino_footer(void)
{
	print_tetrimino_horizontal_line();
}

static void	print_tetrimino_block(t_ttrmn *tetrimino)
{
	int		x;
	int		y;
	int		block_count;
	char	print_char;

	y = -1;
	while (++y < TM_GRID_SIZE)
	{
		x = -1;
		ft_putchar('|');
		while (++x < TM_GRID_SIZE)
		{
			block_count = -1;
			print_char = C_SPACE;
			while (++block_count < TM_BLOCK_COUNT)
			{
				if (tetrimino->coord[block_count].x == x
					&& tetrimino->coord[block_count].y == y)
					print_char = C_BLOCK;
			}
			ft_putchar(print_char);
		}
		ft_putendl("|");
	}
}

/*!
** @brief	print tetrimino (all tetrimino)
** @param	v	fillit variables (structure)
** @return	none
*/
void	print_tetrimino(t_vars *v)
{
	t_list		*ttrmns_loop;
	t_ttrmn		*tetrimino;

	ttrmns_loop = v->ttrmns;
	while (ttrmns_loop)
	{
		tetrimino = (t_ttrmn *)ttrmns_loop->content;
		print_tetrimino_header(tetrimino);
		print_tetrimino_block(tetrimino);
		print_tetrimino_footer();
		ttrmns_loop = ttrmns_loop->next;
	}
}
