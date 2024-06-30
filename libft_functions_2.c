/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:10:43 by amecani           #+#    #+#             */
/*   Updated: 2024/06/30 21:11:08 by amecani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;
	size_t	cj;

	cj = ft_strlen((char *)s1);
	i = 0;
	ptr = malloc(sizeof(char) * cj + 1);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	size_finer(long long l)
{
	int	digits;

	digits = 0;
	if (!l)
		return (1);
	if (l < 0)
	{
		l = -l;
		digits++;
	}
	while (l)
	{
		digits++;
		l = l / 10;
	}
	return ((int)digits);
}

char	*ft_itoa(int n)
{
	long long	l;
	char		*ptr;
	int			size;

	if (!n)
		return (ft_strdup("0"));
	l = n;
	size = size_finer(l);
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		l = -l;
	}
	ptr[size] = '\0';
	while ((size || l) && l > 0)
	{
		size--;
		ptr[size] = (l % 10) + 48;
		l = l / 10;
	}
	return (ptr);
}
