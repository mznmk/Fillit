/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 02:42:39 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/15 09:27:59 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static void	init_vars(t_vars *v)
{
	ft_bzero(v->ttrmn_file_buff, TTRMN_MAX_SIZE);
	v->ttrmn_file_size = 0;
	v->ttrmns = NULL;
	v->grid = NULL;
	v->grid_size = 0;
}

static void	free_vars(t_vars *v)
{

// puts("z");
	// if (v->ttrmns)
	// 	ft_lstiter(v->ttrmns, &free);

// puts("y");

	if (v->ttrmns)
		ft_lstclear(&v->ttrmns, &free);

// puts("x");

}

/*!
** @brief	exit fillit
** @param	v			fillit variables (structure)
** @param	message		wanna print message
** @param	success		true: success / false: failure
** @return	none
*/
void	exit_fillit(t_vars *v, char *message, bool success)
{
	free_vars(v);
	if (success)
	{
		print_success_message(message);
		exit(EXIT_SUCCESS);
	}
	else
	{
		print_failure_messsage(message);
		exit(EXIT_FAILURE);
	}
}

/*!
** @brief	check argument (main function's argument)
** @param	argc	argument count
** @param	argv	argument contents
** @return	none
*/
static void	check_argument(t_vars *v, int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		exit_fillit(v, USAGE_MSG_HEADER USAGE_MSG_DESCRIPTION ,false);
}

/*!
** @brief	main (fillit entry point)
** @param	argc	argument count
** @param	argv	argument contents
** @return	status
*/
int	main(int argc, char **argv)
{
	t_vars	v;

// puts("a");

	// init
	init_vars(&v);

// puts("b");

	// check argument
	check_argument(&v, argc, argv);

// puts("c");

	// parse tetrimino file
	parse_tetrimino(&v, argv[1]);
	
// puts("d");

	// print tetrimino
	print_tetrimino(&v);
	
	// solve problem

	// print solution

	// clear
	free_vars(&v);
	
	return (EXIT_SUCCESS);
}
