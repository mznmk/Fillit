/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetrimino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 01:29:45 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/15 23:56:07 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*!
** @brief	read tetrimino file
** @param	v			fillit variables (structure)
** @param	filename	file to store tetrimino
** @return	none
*/
void	read_tetrimino(t_vars *v, char *filename)
{
	int		fd;
	int		close_status;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_OPEN_FILE, false);
	v->file_size = read(fd, v->file_buff, 545);
	if (v->file_size == -1)
		exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_READ_FILE, false);
	if (v->file_size < 20
		|| TMF_MAX_SIZE <= v->file_size)
		exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_PARSE_FILE, false);
	close_status = close(fd);
	if (close_status == -1)
		exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_CLOSE_FILE, false);
	v->file_buff[v->file_size] = C_LF;
}
