
#include "philo.h"

void  p_eat(t_philo *philo)
{
      usleep(philo->time_to_eat * 1000);
      supervisor(P_EAT, philo);
      drop_fork(philo);
      pthread_mutex_lock(&philo->args->root);
      philo->meal_count += 1;
      philo->time_last_meal = get_time();
      pthread_mutex_unlock(&philo->args->root);
}

void  p_sleep(t_philo *philo)
{
      usleep(philo->time_to_sleep * 1000);
      supervisor(P_SLEEP, philo);
}