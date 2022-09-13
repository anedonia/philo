/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:57:06 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/13 18:55:36 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	eat(t_philo *phi)
{
	struct timeval	eat_time;

	if (phi->info->nb_philo > 1)
	{
		pthread_mutex_lock(&(phi->info->forks[phi->l_fork]));
		log_display(*phi);
	}
	pthread_mutex_lock(&(phi->info->forks[phi->r_fork]));
	log_display(*phi);
	phi->etat = EATING;
	log_display(*phi);
	gettimeofday(&eat_time, NULL);
	phi->last_eat = eat_time.tv_sec * 1000 + eat_time.tv_usec / 1000;
	usleep(phi->info->time_eat * 1000);
	phi->nb_meals++;
	if (phi->info->nb_philo > 1)
		pthread_mutex_unlock(&(phi->info->forks[phi->l_fork]));
	pthread_mutex_unlock(&(phi->info->forks[phi->r_fork]));
}

void	ft_sleep(t_philo *philo)
{
	philo->etat = SLEEPING;
	log_display(*philo);
	usleep(philo->info->time_sleep * 1000);
}

void	think(t_philo *philo)
{
	philo->etat = THINKING;
	log_display(*philo);
	philo->etat = WAIT;
}

void	log_display(t_philo philo)
{
	long long		timediff;

	if (philo.info->phi_died || (philo.info->cycles != -1 && philo.info->end))
		return ;
	pthread_mutex_lock(&(philo.info->write));
	timediff = time_stamp(philo.info->start);
	if (philo.etat == EATING)
		printf("%lld %d is eating\n", timediff, philo.numero);
	else if (philo.etat == WAIT)
		printf("%lld %d has taken a fork\n", timediff, philo.numero);
	else if (philo.etat == SLEEPING)
		printf("%lld %d is sleeping\n", timediff, philo.numero);
	else if (philo.etat == THINKING)
		printf("%lld %d is thinking\n", timediff, philo.numero);
	else if (philo.etat == DEAD)
		printf("%lld %d died\n", timediff, philo.numero);
	pthread_mutex_unlock(&(philo.info->write));
}

void	*mdr(void *philo)
{
	t_philo			*phi;

	phi = (t_philo *)philo;
	phi->last_eat = phi->info->start;
	if (phi->numero % 2)
		usleep(10000);
	while (!phi->info->phi_died)
	{
		if (phi->info->cycles != -1 && phi->info->end)
			break ;
		eat(phi);
		ft_sleep(phi);
		think(phi);
	}
	return (NULL);
}
