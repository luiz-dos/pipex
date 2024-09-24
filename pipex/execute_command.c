/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:55:03 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/24 17:08:07 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_in_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
			return (1);
		i++;
	}
	return (0);
}

char	*get_command_path(char *cmd, char **envp)
{
	char	**all_paths;
	char	*current_path;
	char	*path;
	int		i;

	i = 0;
	while ((ft_strnstr(envp[i], "PATH", 4)) == NULL)
		i++;
	all_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (all_paths[i])
	{
		current_path = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(current_path, cmd);
		free(current_path);
		if (((access(path, F_OK)) == 0) && ((access(path, X_OK)) == 0))
		{
			free_array(all_paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_array(all_paths);
	return (NULL);
}

void	execute_command(char *av, char **envp)
{
	char	**cmd;
	char	*command_path;

	if (!find_in_envp(envp))
		exit(1);
	cmd = ft_split(av, ' ');
	if (!cmd)
		return ;
	command_path = get_command_path(cmd[0], envp);
	if (!command_path)
	{
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		free_array(cmd);
		exit(127);
	}
	execve(command_path, cmd, envp);
	free_array(cmd);
	free(command_path);
	perror("execve");
	exit(1);
}
