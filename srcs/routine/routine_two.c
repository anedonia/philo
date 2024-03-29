/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:38:01 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/26 19:27:28 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	death_check(t_info *info)
{
	t_philo	*p;
	int		i;

	p = info->philo;
	i = 0;
	while (!info->phi_died && !info->end)
	{
		while (i < info->nb_philo)
		{
			pthread_mutex_lock(&(info->leat));
			if (last_since(p[i].last_eat) > info->time_die)
				death_check_extention(info, i);
			pthread_mutex_unlock(&(info->leat));
			i++;
			usleep(1000);
		}
		i = 0;
		all_ate(info);
	}
	return (1);
}

void	death_check_extention(t_info *info, int i)
{
	t_philo	*p;

	p = info->philo;
	pthread_mutex_lock(&(info->state));
	p[i].etat = DEAD;
	pthread_mutex_unlock(&(info->state));
	log_display(&(p[i]));
	pthread_mutex_lock(&(info->bonus));
	info->phi_died = 1;
	pthread_mutex_unlock(&(info->bonus));
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
		pthread_mutex_lock(&(in->leat));
		if (ph[i].nb_meals >= in->cycles)
			j++;
		i++;
		pthread_mutex_unlock(&(in->leat));
	}
	if (j == in->nb_philo)
	{
		pthread_mutex_lock(&(in->bonus));
		in->end = 1;
		pthread_mutex_unlock(&(in->bonus));
	}
	return (0);
}

int	args_full_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("invalid argument\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
