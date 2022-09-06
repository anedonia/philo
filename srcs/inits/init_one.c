/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:09:38 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/06 16:18:17 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	init_info(int argc, char **args, t_info *info)
{
	info->nb_philo = ft_atoi(args[1]);
	info->time_die = ft_atoi(args[2]) * 1000;
	info->time_eat = ft_atoi(args[3]) * 1000;
	info->time_sleep = ft_atoi(args[4]) * 1000;
	if (argc == 6)
		info->cycles = ft_atoi(args[5]);
	info->philo = malloc(sizeof(t_philo) * info->nb_philo);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->nb_philo);
	if (!info->philo || !info->forks)
		return (1);
	init_philo(info);
	init_mutex(info);
	return (0);
}

int	init_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		info->philo[i].etat = WAIT;
		info->philo[i].numero = i + 1;
		info->philo[i].info = info;
		info->philo[i].r_fork = i + 1;
		if (i == 0)
			info->philo[i].l_fork = i + 1;
		else
			info->philo[i].l_fork = i;
		show_phi(info->philo[i]);
		i++;
	}
	return (0);
}

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		if (pthread_mutex_init(&(info->forks[i]), NULL))
			return (1);
		i++;
	}
	return (0);
}

void	show_phi(t_philo phi)
{
	printf("r fork %d\n", phi.r_fork);
	printf("l fork %d\n", phi.l_fork);
	printf("phi nb %d\n\n", phi.numero);
}
