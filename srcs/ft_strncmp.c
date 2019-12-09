/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 14:40:19 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/02 14:40:33 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, int size)
{
	if (size == 0)
		return (0);
	while (size != 0)
	{
		if (*s1 != *s2++)
			return (*(unsigned char *)s1 - *(unsigned char *)--s2);
		if (*s1++ == 0)
			break ;
		size--;
	}
	return (0);
}
