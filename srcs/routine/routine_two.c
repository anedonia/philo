/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:38:01 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/09 16:37:21 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	death_check(t_info *info)
{
	t_philo	*p;
	int		i;

	p = info->philo;
	i = 0;
	usleep(1000);
	while (!info->phi_died && !info->end)
	{
		while (i < info->nb_philo)
		{
			if (last_since(p[i].last_eat) > info->time_die && p[i].etat != DEAD)
			{
				p[i].etat = DEAD;
				info->phi_died = 1;
				log_display(p[i]);
			}
			i++;
		}
		usleep(1000);
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
	while (i < in->nb_philo)
	{
		if (ph[i].nb_meals == in->cycles)
			j++;
		i++;
	}
	if (j == in->nb_philo)
		in->end = 1;
	return (0);
}

//faire le checker de cycles 
//trouver comment correctement stopper les threads 
//faire la exit function 
//protéger le death check 
//initialiser la write mutex
//destroy les mutex cf exit fct

//pour l'instant je vais juste check si un phi n'est pas mort a cause de delais 