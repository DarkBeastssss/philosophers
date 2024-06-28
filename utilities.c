#include "philo.h"

long	get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void display_action(t_phedo *phedo ,char *string)
{
	if (phedo->info->state == DEATH)
		return;
	pthread_mutex_lock(phedo->info->lock_print);
	put_str(ft_itoa(get_time()));
	put_c(' ');
	put_str(ft_itoa(phedo->id));
	put_c(' ');
	put_str(string);
	put_c('\n');
	pthread_mutex_unlock(phedo->info->lock_print);
}
