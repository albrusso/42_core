
#include "philo.h"

void  *philo_die(void *_philo)
{
      t_philo     *philo;
      int   i;
      long long   time;
	bool	die;

      philo = (t_philo *)_philo;
	pthread_mutex_lock(&philo->args->root);
	time = philo->args->time_start;
	die = philo->args->stop;
	pthread_mutex_unlock(&philo->args->root);
      while (die == false)
      {
            i = 0;
            while (i < philo->nbr_of_philo)
            {
			if (philo->meal_count >= philo->nbr_of_time && philo->nbr_of_time != -1)
			{
				die = true;
				break ;
			}
                  if (philo[i].meal_count == 0)
                  {
                        if (get_time() - time > philo->time_to_die)
                        {
                              supervisor(P_DIE, &philo[i]);
                              die = true;
                        }
                  }
                  else if (get_time() - philo[i].time_last_meal > philo->time_to_die)
                  {
                        supervisor(P_DIE, &philo[i]);
                        die = true;
                  }
                  if (die == true)
			{
				pthread_mutex_lock(&philo->args->root);
				philo->args->stop = die; 
				pthread_mutex_unlock(&philo->args->root);
                        break ;
			}
                  i++;
            }
            if (die == true)
		{
			pthread_mutex_lock(&philo->args->root);
			philo->args->stop = die; 
			pthread_mutex_unlock(&philo->args->root);
                  break ;
		}
		usleep(10);
      }
      return (NULL);
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
                  if (philo[i].meal_count == philo->args->nbr_of_time)
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
	pthread_mutex_lock(&philo->args->root);
      philo->time_start = philo->args->time_start;
	pthread_mutex_unlock(&philo->args->root);
      if (philo->nbr_of_time > 0)
      {
            while (philo->nbr_of_time > philo->meal_count)
            {
                  take_fork(philo);
                  p_eat(philo);
                  p_sleep(philo);
                  supervisor(P_THINK, philo);
                  usleep(100);
            }
      }
      else
      {
            while (1)
            {
                  take_fork(philo);
            	p_eat(philo);
            	p_sleep(philo);
            	supervisor(P_THINK, philo);
                  usleep(100);
                  pthread_mutex_lock(&philo->args->root);
                  if (philo->args->stop == true)
			{
                  	pthread_mutex_unlock(&philo->args->root);
                        break ;
			}
			else
				pthread_mutex_unlock(&philo->args->root);
      	}
      }
      return (NULL);
}

void  one_philo(t_philo *philo)
{
      philo->args->time_start = get_time();
      pthread_mutex_lock(philo->l_fork);
      supervisor(P_TAKE_FORK, philo);
      usleep(philo->args->time_to_die * 1000);
      pthread_mutex_unlock(philo->l_fork);
      supervisor(P_DIE, philo);
      exit(4);
}