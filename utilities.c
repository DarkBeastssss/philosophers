/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:07:10 by amecani           #+#    #+#             */
/*   Updated: 2024/07/02 01:48:50 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long long)(time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	display_action(t_phedo *phedo, char *string)
{
	//long long	timestamp;

	pthread_mutex_lock(&phedo->info->lock_print);
	if (!phedo->info->state)
	{
		pthread_mutex_unlock(&phedo->info->lock_print);
		return ;
	}
	printf("%lld %d %s\n", \
	get_time() - phedo->info->start_t, phedo->id, string);
	//timestamp = get_time() - phedo->info->start_t;
	pthread_mutex_unlock(&phedo->info->lock_print);
}
