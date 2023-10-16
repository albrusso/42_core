
#include "philo.h"

void  p_eat(t_philo *philo)
{
      supervisor(P_EAT, philo);
      usleep(philo->args->time_to_eat * 1000);
      pthread_mutex_lock(&philo->args->root);
      philo->meal_count += 1;
      philo->time_last_meal = get_time();
      philo->args->stop = all_eat(philo);
      pthread_mutex_unlock(&philo->args->root);
      drop_fork(philo);
}

void  p_sleep(t_philo *philo)
{
      supervisor(P_SLEEP, philo);
      usleep(philo->args->time_to_sleep * 1000);
}