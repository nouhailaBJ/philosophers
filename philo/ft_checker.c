/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <nbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:43:17 by nbjaghou          #+#    #+#             */
/*   Updated: 2021/07/02 13:19:55 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_checker(void)
{
	int				i;
	unsigned long	diff;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < g_data.nb_philo)
		{
			diff = get_time() - g_data.philo[i].last_meal;
			if (diff > g_data.time_to_die && g_data.philo[i].status != EATING
				&& g_data.philo[i].nb_eat != g_data.nb_meal)
			{
				g_data.philo[i].status = DEAD;
				ft_print("died", g_data.philo[i].nb,
					get_time() - g_data.time_current);
				exit (0);
			}
			i++;
		}
		i--;
		if (g_data.is_meal && g_data.philo[i].nb_eat == g_data.nb_meal - 1)
			break ;
		usleep(100);
	}
}
