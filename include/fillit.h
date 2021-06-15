/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 02:39:19 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/16 00:35:07 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

// ================================== const ================================= //

# define C_BLOCK					'#'
# define C_SPACE					'.'
# define C_LF						'\n'
# define C_NULL						'\0'
# define TM_GRID_SIZE				4
# define TM_BLOCK_COUNT				4

# define TMF_LINE_SIZE				5
# define TMF_SNGL_SIZE				20
# define TMF_MAX_SIZE				545

// -------------------------------- message --------------------------------- //

# define USAGE_MSG_HEADER			"USAGE: "
# define ERROR_MSG_HEADER			"ERROR: "
# define SUCCESS_MSG_HEADER			"SUCCESS: "

# define USAGE_MSG_DESCRIPTION		"./fillit [ Tetrimino's FilePath ]"
# define ERROR_FAIL_OPEN_FILE		"fail to open Tetrimino's File ..."
# define ERROR_FAIL_READ_FILE		"fail to read Tetrimino's File ..."
# define ERROR_FAIL_CLOSE_FILE		"fail to close Tetrimino's File ..."
# define ERROR_FAIL_PARSE_FILE		"fail to parse Tetrimino's File ..."
# define ERROR_FAIL_ALLOCATE_MEMORY	"fail to allocate memory ..."
# define SUCCESS_SOLVE_PROBLEM		"solve problem !!"

// --------------------------------- color ---------------------------------- //

# define ESC_RESET					"\033[0m"
# define ESC_FNT_BOLD				"\033[1m"
# define ESC_FNT_FINE				"\033[2m"
# define ESC_FNT_ITALIC				"\033[3m"
# define ESC_FNT_ULINE				"\033[4m"
# define ESC_CLR_BLACK				"\033[38;5;00m"
# define ESC_CLR_RED				"\033[38;5;01m"
# define ESC_CLR_GREEN				"\033[38;5;02m"
# define ESC_CLR_YELLOW				"\033[38;5;03m"
# define ESC_CLR_BLUE				"\033[38;5;04m"
# define ESC_CLR_MAGENTA			"\033[38;5;05m"
# define ESC_CLR_CYAN				"\033[38;5;06m"
# define ESC_CLR_WHITE				"\033[38;5;07m"
# define ESC_CLR_PINK				"\033[38;5;213m"

// ================================= library ================================ //

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

// ================================= struct ================================= //

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_ttrmn
{
	t_coord		coord[TM_BLOCK_COUNT];
	t_coord		offset;
	char		print_letter;
}				t_ttrmn;

// --------------------------------- struct --------------------------------- //

typedef struct s_vars
{
	t_list		*ttrmns;
	char		file_buff[TMF_MAX_SIZE];
	int			file_size;
	char		**grid;
	int			grid_size;

}				t_vars;

// ========================= prototype declaration ========================== //

void	exit_fillit(t_vars *v, char *message, bool success);

void	parse_tetrimino(t_vars *v, char *filename);
void	read_tetrimino(t_vars *v, char *filename);
void	validate_tetrimino(t_vars *v);

void	solve_problem(t_vars *v);
bool	try_solve_problem(char **grid, int grid_size, t_list *ttrmns);

void	create_grid(t_vars *v);
void	free_grid(t_vars *v);

void	print_tetrimino(t_vars *v);

void	print_solution(t_vars *v);

void	print_message(char *message);
void	print_success_message(char *message);
void	print_failure_messsage(char *message);

#endif
