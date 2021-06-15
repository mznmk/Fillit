/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tetrimino.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:36:57 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/15 10:09:36 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static bool	validate_tetrimino_block_count(t_vars *v, int buff_index)
{
	int		i;
	int		block_count;

	i = -1;
	block_count = 0;
	while (++i < TTRMN_SINGLE_SIZE - 1)
	{
		if (v->ttrmn_file_buff[buff_index + i] != '#'
			&& v->ttrmn_file_buff[buff_index + i] != '.'
			&& v->ttrmn_file_buff[buff_index + i] != '\n')
			return (false);
		if (v->ttrmn_file_buff[buff_index + i] == '\n'
			&& (i + 1) % 5 != 0)
			return (false);
		if (v->ttrmn_file_buff[buff_index + i] == '#')
			block_count++;
	}
	if (v->ttrmn_file_buff[buff_index + TTRMN_SINGLE_SIZE - 1] != '\n'
		&& v->ttrmn_file_buff[buff_index + TTRMN_SINGLE_SIZE - 1] != '\0')
		return (false);
	if (block_count == TETRIMINO_BLOCK_COUNT)
		return (true);
	return (false);
}

static bool	validate_tetrimino_adjacent_count(t_vars *v, int buff_idx)
{
	int		i;
	int		adjacent_count;

	i = -1;
	adjacent_count = 0;
	while (++i < TTRMN_SINGLE_SIZE)
	{
		if (v->ttrmn_file_buff[buff_idx + i] == '#')
		{
			if ((0 <= i - 1) && (v->ttrmn_file_buff[buff_idx + i - 1] == '#'))
				adjacent_count++;
			if ((i + 1 <= TTRMN_SINGLE_SIZE)
				&& (v->ttrmn_file_buff[buff_idx + i + 1] == '#'))
				adjacent_count++;
			if ((0 <= i - TTRMN_LINE_SIZE)
				&& (v->ttrmn_file_buff[buff_idx + i - TTRMN_LINE_SIZE] == '#'))
				adjacent_count++;
			if ((i + TTRMN_LINE_SIZE <= TTRMN_SINGLE_SIZE)
				&& (v->ttrmn_file_buff[buff_idx + i + TTRMN_LINE_SIZE] == '#'))
				adjacent_count++;
		}
	}
	if (adjacent_count == 6 || adjacent_count == 8)
		return (true);
	return (false);
}

/*!
** @brief	validate tetrimino
** @param	v	fillit variables (structure)
** @return	none
*/
void	validate_tetrimino(t_vars *v)
{
	int		buff_index;

	buff_index = 0;
	while (buff_index < v->ttrmn_file_size)
	{
		if (!validate_tetrimino_block_count(v, buff_index))
			exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_PARSE_FILE, false);
		if (!validate_tetrimino_adjacent_count(v, buff_index))
			exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_PARSE_FILE, false);
		buff_index += (TTRMN_SINGLE_SIZE + 1);
	}
}
