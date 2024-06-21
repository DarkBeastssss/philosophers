/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:02:39 by amecani           #+#    #+#             */
/*   Updated: 2024/06/20 19:55:29 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	insert_values(char **av, int ac)
{
	t_i	*i;

	i = malloc(sizeof(t_i));
	if (ac != 5 || ac != 6)
		return (ft_printf("Provide :\n\
	(1) number_of_philosophers\
	(2) time_to_die\
	(3) time_to_eat\
	(4) time_to_sleep\
	(optional) number_of_times_each_philosopher_must_eat\n"\
	, 1));
	if (!ft_atoi(av[1]) || !ft_atoi(av[5]))
		return (ft_printf("Values cannot be zero"), 1);
	i->philos = ft_atoi(av[1]);
	i->time2die = ft_atoi(av[2]);
	i->hungyy = ft_atoi(av[3]);
	i->zzzz = ft_atoi(av[4]);
	if (ac == 6)
		i->bulkin = ft_atoi(av[5]);
}

int	main(int ac, char **av)
{
	t_i			*i;

	if (!insert_values(av, ac))
		return (1);
	if (!more_initinialasition(av, ac))
		return (1);
}
