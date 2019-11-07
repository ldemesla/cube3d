/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:56:17 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/07 12:46:29 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *str, int c, int n)
{
	unsigned char	value;
	int				size;

	if (str == 0)
		return (0);
	value = (unsigned char)c;
	size = 0;
	while (size < n)
	{
		((char *)str)[size] = value;
		size++;
	}
	return (str);
}
