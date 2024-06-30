/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:07:10 by amecani           #+#    #+#             */
/*   Updated: 2024/06/30 21:15:06 by amecani          ###   ########.fr       */
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
	long long	timestamp;

	pthread_mutex_lock(&phedo->info->lock_print);
	if (!phedo->info->state)
	{
		pthread_mutex_unlock(&phedo->info->lock_print);
		return ;
	}
	put_str(ft_itoa(get_time() - phedo->info->start_t));
	put_c(' ');
	put_str(ft_itoa(phedo->id));
	put_c(' ');
	put_str(string);
	put_c('\n');
	timestamp = get_time() - phedo->info->start_t;
	pthread_mutex_unlock(&phedo->info->lock_print);
}

	// printf("%lld %d %s\n", timestamp, phedo->id, string);
