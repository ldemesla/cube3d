/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldemesla <ldemesla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:38:30 by ldemesla          #+#    #+#             */
/*   Updated: 2019/11/02 17:26:29 by ldemesla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*remove_space(char *line)
{
	int		size;
	char	*temp;
	int		i;
	int		o;

	i = 0;
	o = 0;
	size = ft_strlen_map(line);
	if (!(temp = malloc(sizeof(char) * (size + 1))))
		return (0);
	while (line[i])
	{
		if ((line[i] >= '0' && line[i] <= '4') || line[i] == 'N' ||
			line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
			temp[o++] = line[i];
		i++;
	}
	temp[o] = '\0';
	return (temp);
}

int		check_extension(char *line)
{
	int i;
	int	o;

	i = 0;
	o = 0;
	while (line[i] != '.')
		i++;
	if (line[i + 1] != 'c' || line[i + 2] != 'u' || line[i + 3] != 'b'
		|| line[i + 4] != '\0')
	{
		write(1, "Error\nIncorrect file type\n", 26);
		return (-1);
	}
	return (open(line, O_RDONLY));
}

int		ft_compare(char *set, char *line)
{
	int i;
	int	size;
	int	count;

	i = 0;
	size = ft_strlen(set);
	count = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			if (line[i] != set[count])
				return (1);
			count++;
		}
		if (count == size)
			return (0);
		i++;
	}
	return (1);
}

char	*to_file(char *line, char c)
{
	if (c == '/')
	{
		while (*line != c && *line)
			line++;
	}
	else
		while (*line != 'R' && *line != 'C' && *line != 'F' && *line)
			line++;
	return (line + 1);
}
