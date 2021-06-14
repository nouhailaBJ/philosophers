#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
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
    pthread_t philo_check;
    pthread_mutex_t *forks;
    pthread_mutex_t print;
}           t_data;

t_data g_data;

long long time_current(void) {
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}

void stock_data(char **av, int ac)
{
    g_data.nb_of_philo = atoi(av[1]);
    g_data.time_to_die = atoi(av[2]);
    g_data.time_to_eat = atoi(av[3]);
    g_data.time_to_sleep = atoi(av[4]);
    g_data.time_current = time_current();

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

void    ft_print(char *msg, int n, int time)
{
    pthread_mutex_lock(&g_data.print);
    printf("%d %d %s\n", time, n, msg);
    pthread_mutex_unlock(&g_data.print);
}



void *ft_philo(void *val)
{
    while(1)
    {
        int n;

        n = (long) val + 1;
        pthread_mutex_lock(&g_data.forks[n]);
        ft_print("has taken left fork", n, time_current() - g_data.time_current);
        pthread_mutex_lock(&g_data.forks[((n - 1) % g_data.nb_of_philo)]);
        ft_print("has taken right fork", n,  time_current() - g_data.time_current);
        ft_print("is eating", n, time_current() - g_data.time_current);
        //g_data.time_current += g_data.time _to_eat;
        usleep(g_data.time_to_eat  * 1000);
        pthread_mutex_unlock(&g_data.forks[n]);
        pthread_mutex_unlock(&g_data.forks[(n - 1) % g_data.nb_of_philo]);
        ft_print("is sleeping", n, time_current() - g_data.time_current);
        usleep(g_data.time_to_sleep * 1000);
        ft_print("is thinking", n,  time_current() - g_data.time_current);
    }
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
void *ft_checker(void *val)
{
    while (1)
    {
        
    }
}
int main(int ac, char **av)
{
    if (ac == 5 || ac == 6)
    {
        stock_data(av, ac);
        ft_philosophers();
        pthread_create(&g_data.philo_check, NULL, (void *)ft_checker, NULL);
    }
    else
        printf("Syntax: Error \n");
}

// 4 410 200 200 no one die 
// 5 800 200 200
// 4 310 200 100 one should die
// 2 60 60 60