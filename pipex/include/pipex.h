/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:54:25 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/20 10:54:26 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/wait.h>
# include <unistd.h>

void	close_fds(int *fd);
void	free_array(char **path);
void	ft_exit(int *fd, char *str, char *message);
void	child_process(int *fd, char **av, char **envp);
void	parent_process(int *fd, char **av, char **envp);
void	execute_command(char *av, char **envp);
char	*get_command_path(char *cmd, char **envp);
void	check_envp(char **envp);
int     find_in_envp(char **envp);
void	handle_dev_random(void);
void	check_commands(char *av);
int     only_space_av(char *str);

#endif /* PIPEX_H */
