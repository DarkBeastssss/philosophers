/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:02:44 by amecani           #+#    #+#             */
/*   Updated: 2024/06/26 13:50:53 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>

typedef struct s_info
{
	pthread_mutex_t	*lock_1;
	pthread_mutex_t	*lock_2;
	int		philos;
	int		die2time;
	int		hungyy;
	int		zzzz;
	int		pasta_overload;
	bool	state;
	t_phedo		*phedo;
}	t_i;

	// int lounge_id; // is the order 1 3 5 (wait till 1 finished eating) 2 4
	// int caution_id; // would be the second number
typedef struct s_phedo
{
	int id;
	pthread_mutex_t	l_frok;
	pthread_mutex_t	*r_frok;

}	t_phedo;

#ifndef philosopher
# define philosopher

# include <stdlib.h>
# include <stdio.h>

# define DEATH		1
# define CHILLIN	0

//////////////////////////	NODE_UTILS	//////////////////////////

//////////////////////////	THREAD_UTILS	//////////////////////////

//////////////////////////	PARSE	//////////////////////////

		//. G E N IU S  T oo L S \\.

#endif
//