/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbjaghou <nbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:04:05 by nbjaghou          #+#    #+#             */
/*   Updated: 2021/07/02 14:34:58 by nbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "utils/utils.h"
# define THINKING 1
# define EATING 2
# define SLEEPING 3
# define TAKEN_FORK 4
# define DEAD 5

typedef struct s_philo
{
	int				nb;
	int				nb_eat;
	unsigned long	last_meal;
	int				status;
	pthread_t		philo_p;
	pthread_mutex_t	m_eat;
}					t_philo;
typedef struct s_data
{
	int				nb_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				is_meal;
	int				nb_meal;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	m_print;
	unsigned long	time_current;
}					t_data;
t_data	g_data;
void			stock_data(char **av);
int				check_errors(char **av);
unsigned long	get_time(void);
void			fill_philo(int i);
void			ft_initialise(void);
void			ft_sleeping(t_philo *philo);
void			ft_think(t_philo *philo);
void			ft_eat(t_philo *philo);
void			ft_checker(void);
void			*ft_philo(void *philo_v);
void			ft_philosophers2(void);
void			ft_philosophers(void);
void			ft_print(char *msg, int n, int time);
#endif
