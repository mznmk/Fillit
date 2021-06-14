/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 02:42:39 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/14 18:53:30 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*!
** @brief	exit fillit
** @param	message		wanna print message
** @param	success		true: success / false: failure
** @return	none
*/
static void	exit_fillit(char *message, bool success)
{
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
static void	check_argument(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		exit_fillit(USAGE_MSG_HEADER USAGE_MSG_DESCRIPTION ,false);
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

	// check argument
	check_argument(argc, argv);
	// init

	// parse tetrimino file

	// solve problem

	// print solution

	// clear

	return (EXIT_SUCCESS);
}
