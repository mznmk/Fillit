/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 02:39:19 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/14 18:44:27 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

// ================================== const ================================= //

# define TETRIMINO_BLOCK_COUNT		4
# define TETRIMINO_CONTAINER_SIZE	4

// -------------------------------- message --------------------------------- //

# define USAGE_MSG_HEADER			"USAGE: "
# define ERROR_MSG_HEADER			"ERROR: "
# define SUCCESS_MSG_HEADER			"SUCCESS: "

# define USAGE_MSG_DESCRIPTION		"./fillit [ Tetrimino's FilePath ]"




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

// ================================= struct ================================= //

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_tetrimino
{
	t_coord		coord[TETRIMINO_BLOCK_COUNT];
	t_coord		offset;
	char		print_letter;
}				t_tetrimino;

// --------------------------------- struct --------------------------------- //

typedef struct s_vars
{
	t_list		**tetriminos;
	char		**grid;
	int			grid_size;

}				t_vars;

// ========================= prototype declaration ========================== //





void	print_message(char *message);
void	print_success_message(char *message);
void	print_failure_messsage(char *message);





#endif
