/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:48:52 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/30 17:08:21 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_dev_random(void)
{
	char	buffer[1024];
	int		bytes_read;
	int		total_bytes;

	total_bytes = 0;
	while ((bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
	{
		write(STDOUT_FILENO, buffer, bytes_read);
		total_bytes += bytes_read;
		if (total_bytes >= 1024)
			break ;
	}
	exit(0);
}

int	only_space_av(char *str)
{
	int i;

	i = 0;
	while(str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	check_commands(char *av)
{
    if (only_space_av(av))
    {
		ft_putstr_fd(av, 2);
		ft_putstr_fd(": command not found\n", 2);
        exit(127);
    }
}
