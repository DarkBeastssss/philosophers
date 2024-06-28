/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:22:18 by amecani           #+#    #+#             */
/*   Updated: 2024/06/28 13:44:37 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(const char *bomba)
{
	int	i;
	int	charge;
	int	result;

	i = 0;
	charge = 1;
	result = 0;
	while (bomba[i] && (bomba[i] == ' ' || bomba[i] == '\t'
			|| bomba[i] == '\n' || bomba[i] == '\r'
			|| bomba[i] == '\f' || bomba[i] == '\v'))
		i++;
	if (bomba[i] && (bomba[i] == '-' || bomba[i] == '+'))
	{
		if (bomba[i] == '-')
		{
			charge *= -1;
		}
		i++;
	}
	while (bomba[i] && (bomba[i] <= '9' && bomba[i] >= '0'))
	{
		result = result * 10 + (bomba[i] - 48);
		i++;
	}
	return (result * charge);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*u;

	u = (char *)s;
	i = 0;
	while (i < n)
	{
		u[i++] = '\0';
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!(ptr))
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	put_c(char c)
{
	write (1, &c, 1);
}

void	put_str(char *s)
{
	int i;

	i = 0;
	while (s[i])
		put_c(s[i++]);
}