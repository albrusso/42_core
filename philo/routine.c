
#include "philo.h"

bool  philo_die(t_philo *philo)
{
      pthread_mutex_lock(&philo->args->root);
      if (philo->meal_count == 0)
      {
            if (get_time() - philo->time_start >= philo->args->time_to_die)
                  {
                        supervisor(P_DIE, philo);
                        pthread_mutex_unlock(&philo->args->root);
                        return (true);
                  }
      }
      else if ((get_time() - philo->time_last_meal >= philo->args->time_to_die))
      {
            supervisor(P_DIE, philo);
            pthread_mutex_unlock(&philo->args->root);
            return (true);
      }
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
      if (philo->args->nbr_of_time > 0)
      {
            while (philo->args->nbr_of_time > philo->meal_count && philo->args->stop == false)
            {
                  take_fork(philo);
                  p_eat(philo);
                  p_sleep(philo);
                  supervisor(P_THINK, philo);
                  philo_die(philo);
            }
      }
      else
      {
            while (1)
            {
            	if (philo->args->nbr_of_philo == 1)
            	{
                  	take_fork(philo);
                 		usleep(philo->args->time_to_die * 1000);
                 		pthread_mutex_unlock(philo->r_fork);
                 		supervisor(P_DIE, philo);
		      	philo->args->stop = true;
            	}
            	else
            	{     
                  	take_fork(philo);
                  	p_eat(philo);
                  	p_sleep(philo);
                  	supervisor(P_THINK, philo);
				philo->args->stop = philo_die(philo);
            	}
            	if (philo->args->stop == true)
                  	break ;
      	}     
      }
      return (NULL);
}

void  one_philo(t_philo *philo)
{
      philo->time_start = get_time();
      pthread_mutex_lock(philo->l_fork);
      supervisor(P_TAKE_FORK, philo);
      usleep(philo->args->time_to_die * 1000);
      pthread_mutex_unlock(philo->l_fork);
      supervisor(P_DIE, philo);
      exit(4);
}