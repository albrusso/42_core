
#include "philo.h"

bool  philo_die(t_philo *philo)
{
      pthread_mutex_lock(&philo->args->root);
      if ((philo->meal_count!= 0) && (get_time() - philo->time_last_meal >= philo->args->time_to_die))
            return (false);
      pthread_mutex_unlock(&philo->args->root);
      return (true);
}

void  *routine(void *_philo)
{
      t_philo     *philo;

      philo = (t_philo *)_philo;
      while (1)
      {
            if (philo_die(philo) == false)
                  exit(1);
            p_eat(philo);
            p_sleep(philo);
            supervisor(P_THINK, philo);
      }
      return (NULL);
}