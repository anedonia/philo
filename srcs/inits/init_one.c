/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:09:38 by ldevy             #+#    #+#             */
/*   Updated: 2022/08/31 17:22:35 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	init_info(int argc, char **args, t_info *info)
{
	info->nb_philo = ft_atoi(args[1]);
	info->time_die.tv_usec = ft_atoi(args[2]);
	info->time_eat.tv_usec = ft_atoi(args[3]);
	info->time_sleep.tv_usec = ft_atoi(args[4]);
	if (argc == 6)
		info->cycles = ft_atoi(args[5]);
	info->philo = malloc(sizeof(t_philo) * info->nb_philo);
	return (0);
}

int	init_philo(t_info *info)
{
	int	i;

	i = 0;
}

int	threads_init(t_info *info)
{
	int			i;

	i = 0;
	while (i < info->nb_philo)
	{
		info->list_thread[i] = malloc(sizeof(pthread_t));
		if (!info->list_thread[i])
			return (1);
		i++;
	}
	info->list_thread[i] = malloc(sizeof(pthread_t));
	info->list_thread[i] = NULL;
	return (0);
}
