/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetrimino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 01:29:45 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/15 10:00:51 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	read_tetrimino(t_vars *v, char *filename)
{
	int		fd;
	int		close_status;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_OPEN_FILE, false);
	v->ttrmn_file_size = read(fd, v->ttrmn_file_buff, 545);
	if (v->ttrmn_file_size == -1)
		exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_READ_FILE, false);
	if (v->ttrmn_file_size < 20
		|| TTRMN_MAX_SIZE <= v->ttrmn_file_size)
		exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_PARSE_FILE, false);
	close_status = close(fd);
	if (close_status == -1)
		exit_fillit(v, ERROR_MSG_HEADER ERROR_FAIL_CLOSE_FILE, false);
	v->ttrmn_file_buff[v->ttrmn_file_size] = '\n';
}
