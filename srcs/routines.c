/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:57:06 by ldevy             #+#    #+#             */
/*   Updated: 2022/08/30 18:06:33 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philo *philo)
{
	philo->etat = EATING;
	log_display(*philo);
	usleep(philo->info.time_eat.tv_sec * 1000);
	gettimeofday(&philo->last_eat, NULL);
}

void	sleep(t_philo *philo)
{
	philo->etat = SLEEPING;
	log_display(*philo);
	usleep(philo->info.time_sleep.tv_sec * 1000);
}

void	think(t_philo *philo)
{
	log_display(*philo);
	philo->etat = THINKING;
}

void	log_display(t_philo philo)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	current.tv_usec = philo.info.start.tv_usec - current.tv_usec;
	if (philo.etat == EATING)
		printf("%ld %d is eating\n", current.tv_usec, philo.numero);
	else if (philo.etat == SLEEPING)
		printf("%ld %d is sleeping\n", current.tv_usec, philo.numero);
	else if (philo.etat == THINKING)
		printf("%ld %d is thinking\n", current.tv_usec, philo.numero);
	else if (philo.etat == DEAD)
		printf("%ld %d died\n", current.tv_usec, philo.numero);
}

void	mdr(t_philo philo)
{
	eat(&philo);
	sleep(&philo);
	think(&philo);
}

	//dans la routine j'ai besoin du num du philo 
	//il doit avoir la fouchette de son num et du num précedent