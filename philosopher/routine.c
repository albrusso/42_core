
#include "philo.h"

bool  philo_die(t_philo *philo)
{
      pthread_mutex_lock(&philo->args->root);
      if ((philo->meal_count!= 0) && (get_time() - philo->time_last_meal >= philo->args->time_to_die))
            return (true);
      pthread_mutex_unlock(&philo->args->root);
      return (false);
}

bool  all_eat(t_philo *philo)
{
      int   i;
      int   j;

      i = 0;
      j = 0;
      if (philo->args->nbr_of_time == -1)
            return (false);
      else
      {
            while (i < philo->args->nbr_of_philo)
            {
                  if (philo->meal_count == philo->args->nbr_of_time)
                        j++;
                  i++;
            }
            if (j == philo->args->nbr_of_philo)
                  return (true);
            return (false);
      }
}

void  *routine(void *_philo)
{
      t_philo     *philo;

      philo = (t_philo *)_philo;
      while (1)
      {
            if (philo_die(philo) == true || all_eat(philo) == true)
                 return (NULL);
            p_eat(philo);
            p_sleep(philo);
            supervisor(P_THINK, philo);
      }
      return (NULL);
}