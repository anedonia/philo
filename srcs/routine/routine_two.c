/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:38:01 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/13 19:03:18 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	death_check(t_info *info)
{
	t_philo	*p;
	int		i;

	p = info->philo;
	i = 0;
	while (!info->phi_died)
	{
		while (i < info->nb_philo)
		{
			pthread_mutex_lock(&(info->state));
			if (last_since(p[i].last_eat) > info->time_die)
			{
				p[i].etat = DEAD;
				log_display(p[i]);
				info->phi_died = 1;
			}
			pthread_mutex_unlock(&(info->state));
			i++;
			usleep(150);
		}
		i = 0;
		all_ate(info);
	}
	return (1);
}

int	all_ate(t_info *in)
{
	int		i;
	int		j;
	t_philo	*ph;

	ph = in->philo;
	i = 0;
	j = 0;
	if (in->cycles == -1)
		return (0);
	while (i < in->nb_philo)
	{
		if (ph[i].nb_meals >= in->cycles)
			j++;
		i++;
	}
	if (j == in->nb_philo)
		in->end = 1;
	return (0);
}
