/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:57:06 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/26 19:12:24 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	eat_pone(t_philo *phi)
{
	if (phi->numero % 2 && phi->info->nb_philo > 1)
	{
		pthread_mutex_lock(&(phi->info->forks[phi->r_fork]));
		log_display(phi);
		pthread_mutex_lock(&(phi->info->forks[phi->l_fork]));
	}
	else
	{
		pthread_mutex_lock(&(phi->info->forks[phi->l_fork]));
		log_display(phi);
		pthread_mutex_lock(&(phi->info->forks[phi->r_fork]));
	}
	eat_ptwo(phi);
	pthread_mutex_unlock(&(phi->info->forks[phi->l_fork]));
	pthread_mutex_unlock(&(phi->info->forks[phi->r_fork]));
}

void	eat_ptwo(t_philo *phi)
{
	struct timeval	eat_time;

	log_display(phi);
	pthread_mutex_lock(&(phi->info->state));
	phi->etat = EATING;
	pthread_mutex_unlock(&(phi->info->state));
	log_display(phi);
	gettimeofday(&eat_time, NULL);
	pthread_mutex_lock(&(phi->info->leat));
	phi->last_eat = eat_time.tv_sec * 1000 + eat_time.tv_usec / 1000;
	phi->nb_meals++;
	pthread_mutex_unlock(&(phi->info->leat));
	usleep(phi->info->time_eat * 1000);
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->state));
	philo->etat = SLEEPING;
	pthread_mutex_unlock(&(philo->info->state));
	log_display(philo);
	usleep(philo->info->time_sleep * 1000);
}

void	think(t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->state));
	philo->etat = THINKING;
	pthread_mutex_unlock(&(philo->info->state));
	log_display(philo);
	pthread_mutex_lock(&(philo->info->state));
	philo->etat = WAIT;
	pthread_mutex_unlock(&(philo->info->state));
}

void	*mdr(void *philo)
{
	t_philo			*phi;

	phi = (t_philo *)philo;
	if (!phi->numero % 2)
		usleep(1000);
	while (!phi->info->phi_died)
	{
		pthread_mutex_lock(&(phi->info->bonus));
		if (phi->info->cycles != -1 && phi->info->end)
		{
			pthread_mutex_unlock(&(phi->info->bonus));
			break ;
		}
		pthread_mutex_unlock(&(phi->info->bonus));
		eat_pone(phi);
		ft_sleep(phi);
		think(phi);
	}
	return (NULL);
}
