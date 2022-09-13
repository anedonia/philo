/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:09:38 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/13 18:21:41 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	init_info(int argc, char **args, t_info *info)
{
	info->nb_philo = ft_atoi(args[1]);
	info->time_die = ft_atoi(args[2]);
	info->time_eat = ft_atoi(args[3]);
	info->time_sleep = ft_atoi(args[4]);
	info->phi_died = 0;
	if (argc == 6)
		info->cycles = ft_atoi(args[5]);
	else
		info->cycles = -1;
	info->end = 0;
	if (info_check(*info))
		return (1);
	info->philo = malloc(sizeof(t_philo) * info->nb_philo);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->nb_philo);
	if (!info->philo || !info->forks)
	{
		printf("malloc failed\n");
		return (2);
	}
	init_philo(info);
	if (init_mutex(info))
		return (3);
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
		info->philo[i].last_eat = -1;
		info->philo[i].nb_meals = 0;
		if (i == 0)
			info->philo[i].r_fork = i;
		if (info->nb_philo > 1 && i == 0)
			info->philo[i].l_fork = info->nb_philo - 1;
		else
		{
			info->philo[i].r_fork = i;
			info->philo[i].l_fork = i - 1;
		}
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
		{
			printf("mutex initialization failed\n");
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&(info->write), NULL))
	{
		printf("mutex initialization failed\n");
		return (1);
	}
	if (pthread_mutex_init(&(info->state), NULL))
	{
		printf("mutex initialization failed\n");
		return (1);
	}
	return (0);
}

void	init_time(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		info->philo[i].last_eat = info->start;
		i++;
	}
}

int	info_check(t_info i)
{
	if (i.time_die <= 0 || i.time_eat <= 0 || i.time_sleep <= 0
		|| i.nb_philo <= 0)
	{
		printf("invalid argument\n");
		return (1);
	}
	if (i.cycles != -1 && i.cycles <= 0)
	{
		printf("invalid argument\n");
		return (1);
	}
	return (0);
}
