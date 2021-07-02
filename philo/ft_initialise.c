/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <nbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:39:26 by nbjaghou          #+#    #+#             */
/*   Updated: 2021/07/02 13:19:53 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_philo(int i)
{
	g_data.philo[i].nb = i + 1;
	g_data.philo[i].nb_eat = 0;
	g_data.philo[i].status = THINKING;
	g_data.philo[i].last_meal = get_time();
}

void	ft_initialise(void)
{
	int	i;

	i = 0;
	g_data.philo = (t_philo *)malloc(sizeof(t_philo) * g_data.nb_philo);
	g_data.forks = malloc(sizeof(pthread_mutex_t) * g_data.nb_philo);
	while (i < g_data.nb_philo)
	{
		fill_philo(i);
		pthread_mutex_init(&g_data.forks[i], NULL);
		pthread_mutex_init(&g_data.philo[i].m_eat, NULL);
		i++;
	}
	g_data.time_current = get_time();
	pthread_mutex_init(&g_data.m_print, NULL);
}
