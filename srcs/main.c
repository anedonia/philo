/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:31:58 by ldevy             #+#    #+#             */
/*   Updated: 2022/08/30 19:01:23 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int cmpt = 0;

void	*routine()
{
	for (int i = 0; i < 1000000; i++)
	{
		cmpt++;
	}
	printf("cmpt : %d\n", cmpt);
	return (NULL);
}

void	test_threads(t_info *info)
{
	int	i;
	int	state;

	i = 0;
	while (info->list_thread[i])
	{
		state = pthread_create(info->list_thread[i], NULL, &routine, NULL);
		if (state != 0)
			return ;
		i++;
	}
	i = 0;
	while (info->list_thread[i])
	{
		state = pthread_join((*info->list_thread[i]), NULL);
		if (state != 0)
			return ;
		i++;
	}
}

// int	main(int argc, char **argv)
// {
// 	t_info	info;

// 	(void)argc;
// 	threads_init(ft_atoi(argv[1]), &info);
// 	test_threads(&info);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	struct timeval	start;
	struct timeval	end;

	(void)argc;
	(void)argv;
	for (int i = 0; i < 10; i++)
	{
		gettimeofday(&start, NULL);
		usleep(20000);
		gettimeofday(&end, NULL);
		printf("time diff : %ld\n", end.tv_usec - start.tv_usec);
		printf("start : %ld end %ld\n", start.tv_usec, end.tv_usec);
	}
	return (0);
}

//il faut faire attention usleep est en micro sec pas milli
//les fourchettes sont un tableau daddr partagé entre les threads 
//on peut les différenciers avec 0 ou 1 pour signifier leur etat ?

//besoin de start le temps une fois au debut 