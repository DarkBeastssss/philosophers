/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initinilasiation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:22:23 by amecani           #+#    #+#             */
/*   Updated: 2024/06/30 21:48:40 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_info *info)
{
	if (pthread_mutex_init(&info->lock_done, NULL) != 0)
		return (printf("lock_dead faillll!"), 0);
	if (pthread_mutex_init(&info->lock_dead, NULL) != 0)
		return (pthread_mutex_destroy(&info->lock_done),
			printf("lock_done faillll!\n"), 0);
	if (pthread_mutex_init(&info->lock_print, NULL) != 0)
		return (pthread_mutex_destroy(&info->lock_dead),
			pthread_mutex_destroy(&info->lock_done),
			printf("lock_printy faillll!\n"), 0);
	return (1);
}

int	inserting_args(char **av, int ac, t_info *info)
{
	if (ac != 5 && ac != 6)
		return (put_str(ERROR_MSG), 0);
	if (ac == 6 && ft_atoi(av[5]) == -1)
		return (put_str(ERROR_MSG), 0);
	if (!ft_atoi(av[1]))
		return (put_str("Values cannot be zero\n"), 0);
	if (ac == 6 && !ft_atoi(av[5]))
		return (put_str("Values cannot be zero\n"), 0);
	(info)->pasta_overload = -1;
	(info)->philos = ft_atoi(av[1]);
	(info)->die2time = ft_atoi(av[2]);
	(info)->hungyy = ft_atoi(av[3]);
	(info)->zzzz = ft_atoi(av[4]);
	(info)->state = 1;
	(info)->start_t = get_time();
	if (ac == 6)
		(info)->pasta_overload = ft_atoi(av[5]);
	if (info->philos < 0 | info->die2time < 0 | info->hungyy < 0
		| info->zzzz < 0 | \
		(info->pasta_overload < 0 && info->pasta_overload != -1))
		return (put_str(ERROR_MSG), 0);
	return (1);
}

int	phedo_init(t_phedo *phedo, int id, t_info *info)
{
	phedo->id = id + 1;
	phedo->die_to_time = info->die2time;
	phedo->numnum_count = 0;
	phedo->last_reset = info->start_t;
	phedo->completion = 0;
	phedo->info = info;
	return (1);
}

void	destroy_phedo(t_phedo **philos, int id)
{
	while (id > 0)
	{
		id--;
		pthread_mutex_destroy(&(*philos)[id].r_frok);
		pthread_mutex_destroy(&(*philos)[id].lock_hungyy);
	}
	free(*philos);
}

int	init_phedos(t_phedo **phedos, t_info *info)
{
	int	id;

	id = -1;
	*phedos = malloc(sizeof(t_phedo) * info->philos);
	if (!phedos)
		return (printf("Aint mallocin' cuh!\n"));
	while (++id < info->philos)
	{
		phedo_init(&(*phedos)[id], id, info);
		if (pthread_mutex_init(&(*phedos)[id].r_frok, NULL) != 0)
			return (destroy_phedo(phedos, id), printf("r_fork aint forkin\n"),
				0);
		if (pthread_mutex_init(&(*phedos)[id].lock_hungyy, NULL) != 0)
			return (pthread_mutex_destroy(&(*phedos)[id].r_frok),
				destroy_phedo(phedos, id),
				printf("lock_eating doesnt want to lock\n"), 0);
		if (id)
			(*phedos)[id].l_frok = &(*phedos)[id - 1].r_frok;
	}
	if (info->philos <= 1)
		return (1);
	(*phedos)[0].l_frok = &(*phedos)[info->philos - 1].r_frok;
	return (1);
}
