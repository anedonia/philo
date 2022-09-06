/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:56:55 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/06 15:50:15 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	end_all(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		pthread_mutex_destroy(&(info->forks[i]));
		i++;
	}
	free(info->philo);
}
