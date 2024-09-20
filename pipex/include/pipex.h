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

#endif /* PIPEX_H */
