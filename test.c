#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
/*
    Start.
    Philosopher i is thinking.
    Lock the left fork spoon.
    Lock the right fork spoon.
    Philosopher i is eating.
    sleep
    Release the left fork spoon.
    Release the right fork spoon.
    Philosopher i Finished eating.
    Stop.
*/
typedef struct s_data
{
    int nb_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_must_eat;
    int time_current;
    pthread_t *philo;
    pthread_mutex_t *forks;
}           t_data;

t_data g_data;

void stock_data(char **av, int ac)
{
    g_data.nb_of_philo = atoi(av[1]);
    g_data.time_to_die = atoi(av[2]);
    g_data.time_to_eat = atoi(av[3]);
    g_data.time_to_sleep = atoi(av[4]);
    g_data.time_current = 0;

    if (ac == 6)
        g_data.nb_must_eat = atoi(av[5]);
    else
        g_data.nb_must_eat = -1;
}

int init_forks(void)
{
    int i;

    i = 0;
    g_data.philo = malloc(sizeof(pthread_t) * g_data.nb_of_philo);
    if (!g_data.philo)
        return (-1);
    g_data.forks = malloc(sizeof(pthread_mutex_t) * g_data.nb_of_philo);
    if (!g_data.forks)
        return (-1); 
    while (i < g_data.nb_of_philo)
    {
        pthread_mutex_init(&g_data.forks[i], NULL);
        i++;
    }
    return (0);
}

void *ft_philo(void *val)
{
    // here what the philo doing
    int n;

    n = (long) val + 1;
    printf("%d %d has taken a fork \n", g_data.time_current, n);
    pthread_mutex_lock(&g_data.forks[n]);
    pthread_mutex_lock(&g_data.forks[(n + 1) % g_data.nb_of_philo]);
    printf("%d %d is eating \n", g_data.time_current, n);
    g_data.time_current += g_data.time_to_eat;
    usleep(g_data.time_to_eat);
    printf("%d %d is sleeping \n", g_data.time_current, n);
    g_data.time_current += g_data.time_to_sleep;
    usleep(g_data.time_to_sleep);
    pthread_mutex_unlock(&g_data.forks[n]);
    pthread_mutex_unlock(&g_data.forks[(n + 1) % g_data.nb_of_philo]);
    printf("%d %d is thinking \n", g_data.time_current, n);
    return (NULL);
}

void create_pthread(void)
{
    int i;

    i = 0;
    while (i < g_data.nb_of_philo)
    {
        pthread_create(&g_data.philo[i], NULL, (void *)ft_philo, (void *)(long)i);
        i++;
    }
    i = 0;
    while (i < g_data.nb_of_philo)
    {
         pthread_join(g_data.philo[i], NULL);
        i++;
    }
}

void destroy_pthread(void)
{
    int i;

    i = 0;
    while (i < g_data.nb_of_philo)
    {
        pthread_mutex_destroy(&g_data.forks[i]);
        i++;
    }
}

void ft_philosophers(void)
{
    if (init_forks() == 0)
    {
        create_pthread();
        destroy_pthread();
    }
    else
        printf("error in initialisation\n");
}

int main(int ac, char **av)
{
    if (ac == 5 || ac == 6)
    {
        stock_data(av, ac);
        ft_philosophers();
    }
    else
        printf("Syntax: Error \n");
}