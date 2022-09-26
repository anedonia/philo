/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:33:15 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/26 19:33:43 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

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
