/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tetrimino.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:36:57 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/15 15:40:30 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static bool	validate_TM_BLOCK_COUNT(t_vars *v, int buff_index)
{
	int		i;
	int		block_count;

	i = -1;
	block_count = 0;
	while (++i < TMF_SNGL_SIZE - 1)
	{
		if (v->file_buff[buff_index + i] != C_BLOCK
			&& v->file_buff[buff_index + i] != C_SPACE
			&& v->file_buff[buff_index + i] != C_LF)
			return (false);
		if (v->file_buff[buff_index + i] == C_LF
			&& (i + 1) % 5 != 0)
			return (false);
		if (v->file_buff[buff_index + i] == C_BLOCK)
			block_count++;
	}
	if (v->file_buff[buff_index + TMF_SNGL_SIZE - 1] != C_LF
		&& v->file_buff[buff_index + TMF_SNGL_SIZE - 1] != C_NULL)
		return (false);
	if (block_count == TM_BLOCK_COUNT)
		return (true);
	return (false);
}

static bool	validate_tetrimino_adjacent_count(t_vars *v, int buff_idx)
{
	int		i;
	int		adjacent_count;

	i = -1;
	adjacent_count = 0;
	while (++i < TMF_SNGL_SIZE)
	{
		if (v->file_buff[buff_idx + i] == C_BLOCK)
		{
			if ((0 <= i - 1) && (v->file_buff[buff_idx + i - 1] == C_BLOCK))
				adjacent_count++;
			if ((i + 1 <= TMF_SNGL_SIZE)
				&& (v->file_buff[buff_idx + i + 1] == C_BLOCK))
				adjacent_count++;
			if ((0 <= i - TMF_LINE_SIZE)
				&& (v->file_buff[buff_idx + i - TMF_LINE_SIZE] == C_BLOCK))
				adjacent_count++;
			if ((i + TMF_LINE_SIZE <= TMF_SNGL_SIZE)
				&& (v->file_buff[buff_idx + i + TMF_LINE_SIZE] == C_BLOCK))
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
	while (buff_index < v->file_size)
	{
		if (!validate_TM_BLOCK_COUNT(v, buff_index))
			exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_PARSE_FILE, false);
		if (!validate_tetrimino_adjacent_count(v, buff_index))
			exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_PARSE_FILE, false);
		buff_index += (TMF_SNGL_SIZE + 1);
	}
}
