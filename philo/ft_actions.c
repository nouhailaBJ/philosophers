/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <nbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:41:19 by nbjaghou          #+#    #+#             */
/*   Updated: 2021/07/02 14:35:18 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleeping(t_philo *philo)
{
	philo->status = SLEEPING;
	ft_print("is sleeping", philo->nb, get_time() - g_data.time_current);
	usleep(g_data.time_to_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	philo->status = THINKING;
	ft_print("is thinking", philo->nb, get_time() - g_data.time_current);
}

void	ft_eat(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&g_data.forks[philo->nb - 1]);
	philo->status = TAKEN_FORK;
	ft_print("has taken a fork", philo->nb, get_time() - g_data.time_current);
	pthread_mutex_lock(&g_data.forks[(philo->nb) % g_data.nb_philo]);
	ft_print("has taken a fork", philo->nb, get_time() - g_data.time_current);
	philo->status = EATING;
	pthread_mutex_lock(&philo->m_eat);
	ft_print("is eating", philo->nb, get_time() - g_data.time_current);
	philo->last_meal = get_time();
	philo->nb_eat++;
	usleep((g_data.time_to_eat - 20) * 1000);
	while ((get_time() - philo->last_meal) < g_data.time_to_eat)
		i++;
	pthread_mutex_unlock(&philo->m_eat);
	pthread_mutex_unlock(&g_data.forks[philo->nb - 1]);
	pthread_mutex_unlock(&g_data.forks[(philo->nb) % g_data.nb_philo]);
}
