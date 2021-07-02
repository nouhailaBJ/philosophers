/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <nbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:15:24 by nbjaghou          #+#    #+#             */
/*   Updated: 2021/07/02 14:33:37 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(char *msg, int n, int time)
{
	pthread_mutex_lock(&g_data.m_print);
	printf("%d %d %s\n", time, n, msg);
	pthread_mutex_unlock(&g_data.m_print);
}

unsigned long	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	check_errors(char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0)
			return (1);
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	stock_data(char **av)
{
	g_data.nb_philo = ft_atoi(av[1]);
	g_data.time_to_die = ft_atoi(av[2]);
	g_data.time_to_eat = ft_atoi(av[3]);
	g_data.time_to_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		g_data.is_meal = 1;
		g_data.nb_meal = ft_atoi(av[5]);
	}
	else
	{
		g_data.is_meal = 0;
		g_data.nb_meal = -1;
	}
}	
