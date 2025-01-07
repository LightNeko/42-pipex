/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:02:50 by znicola           #+#    #+#             */
/*   Updated: 2025/01/07 19:27:27 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_prgpar
{
	int		infile;
	int		outfile;
	char	**cmd1;
	char	**cmd2;
}	t_prgpar;

void	pipex(t_prgpar data, char **envp);
void	data_cleanup(t_prgpar *data);

#endif
