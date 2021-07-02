/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <nbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:23:11 by nbjaghou          #+#    #+#             */
/*   Updated: 2021/07/02 14:34:45 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("ERROR: Wrong Syntax \n");
		return (EXIT_FAILURE);
	}
	if (check_errors(av) == 0)
	{
		stock_data(av);
		ft_initialise();
		ft_philosophers();
	}
	else
	{
		printf("ERROR: Not a valid arguments \n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
