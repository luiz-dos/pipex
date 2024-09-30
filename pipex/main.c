/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:54:43 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/20 12:12:21 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *fd, char **av, char **envp)
{
	int	fd_in;

	if ((access(av[1], F_OK)) == -1)
		ft_exit(fd, av[1], ": No such file or directory\n");
	fd_in = open(av[1], O_RDONLY);
	if (fd_in == -1)
		ft_exit(fd, av[1], ": Permission denied\n");
	dup2(fd_in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd_in);
	close_fds(fd);
	if (ft_strncmp(av[1], "/dev/random", 11) == 0)
		handle_dev_random();
	else
		execute_command(av[2], envp);
}

void	parent_process(int *fd, char **av, char **envp)
{
	int	fd_out;

	fd_out = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		ft_exit(fd, av[4], ": Permission denied\n");
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close_fds(fd);
	execute_command(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	pid;

	check_envp(envp);
	if (ac == 5)
	{
		if (pipe(fd) == -1)
			exit(1);
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
			child_process(fd, av, envp);
		else
		{
			wait(NULL);
			parent_process(fd, av, envp);
		}
	}
	else
	{
		write(2, "Invalid number of arguments\n", 28);
		exit(2);
	}
	return (0);
}
