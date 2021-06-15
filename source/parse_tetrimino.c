/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:29:02 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/15 15:32:16 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	extract_tetrimino(
			t_vars *v, t_ttrmn *tetrimino, int buff_index, char print_letter)
{
	int		i;
	int		block_counter;

	i = -1;
	block_counter = 0;
	while (++i < TMF_SNGL_SIZE)
	{
		if (v->file_buff[buff_index + i] == C_BLOCK)
		{
			tetrimino->coord[block_counter].x = i % 5;
			tetrimino->coord[block_counter].y = i / 5;
			block_counter++;
		}
	}
	tetrimino->offset.x = 0;
	tetrimino->offset.y = 0;
	tetrimino->print_letter = print_letter;
}

/*!
** @brief	parse tetrimino
** @param	v	fillit variables (structure)
** @return	none
*/
void	parse_tetrimino(t_vars *v, char *filename)
{
	t_ttrmn		*tetrimino;
	t_list		*list;
	int			buff_index;
	char		print_letter;

	read_tetrimino(v, filename);
	validate_tetrimino(v);
	buff_index = 0;
	print_letter = 'A';
	while (buff_index < v->file_size)
	{
		tetrimino = (t_ttrmn *)malloc(sizeof(t_ttrmn) * 1);
		if (!tetrimino)
			exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_ALLOCATE_MEMORY, false);
		extract_tetrimino(v, tetrimino, buff_index, print_letter);
		list = ft_lstnew(tetrimino);
		if (!list)
			exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_ALLOCATE_MEMORY, false);
		ft_lstadd_back(&v->ttrmns, list);
		buff_index += (TMF_SNGL_SIZE + 1);
		print_letter++;
	}
}
