/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 05:58:50 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/14 18:15:49 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*!
** @brief	print message
** @param	message		wanna print message
** @return	none
*/
void	print_message(char *message)
{
	ft_putstr(ESC_FNT_BOLD ESC_CLR_YELLOW);
	ft_putendl(message);
	ft_putstr(ESC_RESET);
}

/*!
** @brief	print success message
** @param	message		wanna print message
** @return	none
*/
void	print_success_message(char *message)
{
	ft_putstr(ESC_FNT_BOLD ESC_CLR_GREEN);
	ft_putendl(message);
	ft_putstr(ESC_RESET);
}

/*!
** @brief	print failure message
** @param	message		wanna print message
** @return	none
*/
void	print_failure_messsage(char *message)
{
	ft_putstr(ESC_FNT_BOLD ESC_CLR_RED);
	ft_putendl(message);
	ft_putstr(ESC_RESET);
}
