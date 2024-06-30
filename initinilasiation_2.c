/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initinilasiation_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:05:30 by amecani           #+#    #+#             */
/*   Updated: 2024/06/30 21:08:02 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*tummy_check(void *phedos)
{
	t_phedo	*phedo;
	int		full;
	int		i;

	phedo = phedos;
	while (1)
	{
		i = -1;
		full = 0;
		while (++i < phedo->info->philos)
		{
			if (phedo[i].completion == 1)
				full++;
		}
		if (full == phedo->info->philos)
			return (phedo->info->no_crumbs_left = 1, NULL);
		if (!phedo->info->state)
			return (NULL);
		usleep(10);
	}
	return (NULL);
}

void	phedo_in_hell(t_phedo *phedo, long long time)
{
	pthread_mutex_lock(&phedo->info->lock_print);
	phedo->info->state = 0;
	printf("%lld %d died\n", time - phedo->info->start_t, phedo->id);
	usleep(100);
	pthread_mutex_unlock(&phedo->info->lock_print);
	pthread_mutex_unlock(&phedo->info->lock_dead);
}

void	*death_check(void *phedos)
{
	t_phedo		*phedo;
	long long	time;
	int			id;

	phedo = phedos;
	id = -1;
	while (++id < phedo->info->philos)
	{
		pthread_mutex_lock(&phedo[id].info->lock_dead);
		time = get_time();
		if (phedo[id].die_to_time <= time - phedo[id].last_reset)
		{
			return (phedo_in_hell(&phedo[id], time), NULL);
		}
		pthread_mutex_unlock(&phedo[id].info->lock_dead);
		if (phedo->info->no_crumbs_left == 1)
			return (NULL);
		if (id == phedo->info->philos - 1)
			id = -1;
	}
	return (NULL);
}

int	stitch_it_boyyy(t_info *info, t_phedo *phedos)
{
	int			id;
	pthread_t	dead;
	pthread_t	tummy_burst;

	phedos->info->no_crumbs_left = 0;
	phedos->info->state = 1;
	pthread_create(&dead, NULL, death_check, phedos);
	pthread_create(&tummy_burst, NULL, tummy_check, phedos);
	id = 0;
	while (id < info->philos)
	{
		if (pthread_create(&phedos[id].thread, NULL, routine, &phedos[id]))
			return (put_str("Thread Creation Fault\n"), 0);
		id++;
	}
	id = -1;
	while (++id < info->philos)
		pthread_join(phedos[id].thread, NULL);
	return (1);
}
