/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amecani <amecani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:10:43 by amecani           #+#    #+#             */
/*   Updated: 2024/07/02 01:58:12 by amecani          ###   ########.fr       */
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

// char	*ft_strdup(const char *s1)
// {
// 	char	*ptr;
// 	size_t	i;
// 	size_t	cj;

// 	cj = ft_strlen((char *)s1);
// 	i = 0;
// 	ptr = malloc(sizeof(char) * cj + 1);
// 	if (!ptr)
// 		return (NULL);
// 	while (s1[i] != '\0')
// 	{
// 		ptr[i] = s1[i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }
