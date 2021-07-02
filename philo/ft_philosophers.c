/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <nbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:24:34 by nbjaghou          #+#    #+#             */
/*   Updated: 2021/07/02 13:19:51 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo(void *philo_v)
{
	t_philo	*philo;

	philo = (t_philo *)philo_v;
	while (g_data.nb_meal == -1 || philo->nb_eat < g_data.nb_meal)
	{
		ft_eat(philo);
		ft_sleeping(philo);
		ft_think(philo);
	}
	return (NULL);
}

void	ft_philosophers2(void)
{
	int	i;

	i = 0;
	ft_checker();
	i = 0;
	while (i < g_data.nb_philo)
	{
		pthread_join(g_data.philo[i].philo_p, NULL);
		i++;
	}
}

void	ft_philosophers(void)
{
	int	i;

	i = 0;
	while (i < g_data.nb_philo)
	{
		pthread_create(&g_data.philo[i].philo_p, NULL,
			(void *)ft_philo, &g_data.philo[i]);
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < g_data.nb_philo)
	{
		pthread_create(&g_data.philo[i].philo_p, NULL,
			(void *)ft_philo, &g_data.philo[i]);
		i += 2;
	}
	ft_philosophers2();
}
