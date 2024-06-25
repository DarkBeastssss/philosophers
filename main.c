/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:02:39 by amecani           #+#    #+#             */
/*   Updated: 2024/06/25 21:27:40 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	inserting_args(char **av, int ac, t_i *info)
{
	if (ac != 5 || ac != 6)
		return (put_str("Provide :\n\
	(1) number_of_philosophers\
	(2) time_to_die\
	(3) time_to_eat\
	(4) time_to_sleep\
	(optional) number_of_times_each_philosopher_must_eat\n"\
	, 1));
	if (!ft_atoi(av[1]) || !ft_atoi(av[5]))
		return (put_str("Values cannot be zero"), 0);
	info = malloc(sizeof(t_i));
	if (!info)
		return (put_str("Malloc failed"), 0);
	info->philos = ft_atoi(av[1]);
	info->die2time = ft_atoi(av[2]);
	info->hungyy = ft_atoi(av[3]);
	info->zzzz = ft_atoi(av[4]);
	if (ac == 6)
		info->pasta_overload = ft_atoi(av[5]);
	return (1);
}

void init_phedo(int i, t_phedo *phedo)
{
	phedo->id = i;
	pthread_mutex_init(phedo->l_frok, NULL);
}

static int init_stuff(t_i **info)
{
	t_phedo	*phedo;

	int		i = 0;

	phedo = malloc (sizeof(t_phedo) * info->philos);
	if (pthread_mutex_init(info->lock_1, NULL) || !phedo)
		return (0);
	
	while (i < info->philos)
	{
		if (i + 1 == info->philos)
			*info->phedo[i].r_frok = info->phedo[0]->l_frok;
		else
			*info->phedo[i]->r_frok = info->philos[i + 1]
			// info->phedo[i]->r_frok = &info->phedo[i + 1]->l_frok;
		init_phedo(i, &info->phedo[i++]);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_i			*info;

	info = 0;
	if (!inserting_args(av, ac, info))
		return (1);
	if (!init_stuff(info))
		return (1);
	start();
}