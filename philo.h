/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:02:44 by amecani           #+#    #+#             */
/*   Updated: 2024/06/20 19:56:27 by amecani          ###   ########.fr       */
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
	int		philos;
	int		die2time;
	int		hungyy;
	int		zzzz;
	int		pasta_overload;
	bool	state;
}	t_i;

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