/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:56:44 by ldevy             #+#    #+#             */
/*   Updated: 2022/09/05 16:11:09 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	long	i;
	long	nbr;
	int		signe;

	signe = 1;
	i = 0;
	nbr = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (nbr * signe);
}

long long	time_stamp(long long start_time)
{
	long long		timediff;
	struct timeval	current;

	gettimeofday(&current, NULL);
	timediff = current.tv_sec * 1000 + current.tv_usec / 1000;
	timediff -= start_time;
	return (timediff);
}
