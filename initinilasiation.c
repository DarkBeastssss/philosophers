/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initinilasiation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:22:23 by amecani           #+#    #+#             */
/*   Updated: 2024/06/28 18:29:22 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	inserting_args(char **av, int ac, t_info **info)
{
	if (ac != 5 && ac != 6)
		return (put_str("Provide :\n\
	(1) number_of_philosophers\n\
	(2) time_to_die\n\
	(3) time_to_eat\n\
	(4) time_to_sleep\n\
	(5) (optional) number_of_times_each_philosopher_must_eat\n\
	THE NUMBER WILL BE CUT OF FROM THE REST OF THE ARG IF NON-DIGIT PROVIDED (atoi)\n"\
	), 0);
	if (!ft_atoi(av[1]))
		return (put_str("Values cannot be zero"), 0);
	if (ac == 6 && !ft_atoi(av[5]))
		return (put_str("Values cannot be zero"), 0);
	(*info) = ft_calloc(1, sizeof(t_info));
	if (!info)
		return (put_str("Malloc failed"), 0);
	(*info)->pasta_overload = 1;
	(*info)->philos = ft_atoi(av[1]);
	(*info)->die2time = ft_atoi(av[2]);
	(*info)->hungyy = ft_atoi(av[3]);
	(*info)->zzzz = ft_atoi(av[4]);
	if (ac == 6)
		(*info)->pasta_overload = ft_atoi(av[5]);
	return (1);
}

int	init_stuff(t_info *info)
{
	t_phedo	*phedo;

	int		i = 0;

	phedo = ft_calloc (sizeof(t_phedo), info->philos);
	// i need to malloc memory for lock_print first, dam
	if (pthread_mutex_init(info->lock_print, NULL) || \
		pthread_mutex_init(info->lock_dead, NULL)  || \
		!phedo)
		return (0);
	
	while (i < info->philos)
	{
		if (i + 1 == info->philos)
			info->phedo[i].r_frok = &info->phedo[0].l_frok;
		else
		{
			pthread_mutex_init(&info->phedo[i].l_frok, NULL);
			pthread_mutex_init(&info->phedo[i+1].l_frok, NULL);
			info->phedo[i].r_frok = &info->phedo[i + 1].l_frok;
		}
		// other initinialisations
		phedo[i].id = i + 1;
		phedo[i].info = info;
		i++;
	}
	return (1);
}
