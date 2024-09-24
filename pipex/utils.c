/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:48:52 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/24 17:08:21 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	ft_exit(int *fd, char *str, char *message)
{
	if (str)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(str, 2);
	}
	if (message)
		ft_putstr_fd(message, 2);
	close_fds(fd);
	exit(1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	check_envp(char **envp)
{
	if (!envp || !*envp)
	{
		ft_putstr_fd("pipex: environment not found\n", 2);
		exit(1);
	}
}
