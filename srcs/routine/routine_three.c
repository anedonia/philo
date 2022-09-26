/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:16:10 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/26 19:27:32 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	log_display(t_philo *philo)
{
	long long		timediff;

	pthread_mutex_lock(&(philo->info->bonus));
	if (philo->info->phi_died || (philo->info->cycles \
		!= -1 && philo->info->end))
	{
		pthread_mutex_unlock(&philo->info->bonus);
		return ;
	}
	pthread_mutex_unlock(&(philo->info->bonus));
	pthread_mutex_lock(&(philo->info->state));
	pthread_mutex_lock(&(philo->info->write));
	timediff = time_stamp(philo->info->start);
	if (philo->etat == EATING)
		printf("%lld %d is eating\n", timediff, philo->numero);
	else if (philo->etat == WAIT)
		printf("%lld %d has taken a fork\n", timediff, philo->numero);
	else if (philo->etat == SLEEPING)
		printf("%lld %d is sleeping\n", timediff, philo->numero);
	else if (philo->etat == THINKING)
		printf("%lld %d is thinking\n", timediff, philo->numero);
	else if (philo->etat == DEAD)
		printf("%lld %d died\n", timediff, philo->numero);
	pthread_mutex_unlock(&(philo->info->write));
	pthread_mutex_unlock(&(philo->info->state));
}

void	solo_phi(char *str)
{
	printf("0 1 has taken a fork\n");
	printf("%s 1 died\n", str);
}

int	solo_case(int argc, char **argv)
{
	if (args_full_check(argc, argv))
		return (1);
	solo_phi(argv[2]);
	return (1);
}
