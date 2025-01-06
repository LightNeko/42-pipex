/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:12:56 by znicola           #+#    #+#             */
/*   Updated: 2025/01/06 23:31:29 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void init_data( t_prgpar *data, char **argv)
{
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile == -1)
	{
		perror("open file1");
		exit(1);
	}
	data->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile == -1)
	{
		perror("open file2");
		close(data->infile);
		exit(1);
	}
	data->cmd1 = ft_split(argv[2], ' ');
	data->cmd2 = ft_split(argv[3], ' ');	
	if (!data->cmd1 || !data->cmd1[0] || !data->cmd2 || !data->cmd2[0])
	{
		perror("Invalid command");
		close(data->infile);
		close(data->outfile);
		exit(1);
	}
}

static void	data_cleanup(t_prgpar *data)
{
	int i;
	
	close(data->infile);
	close(data->outfile);
	if (data->cmd1)
	{
		i = 0;
		while(data->cmd1[i])
			free(data->cmd1[i++]);
		free(data->cmd1);
	}
	if (data->cmd2)
	{
		i = 0;
		while(data->cmd2[i])
			free(data->cmd2[i++]);
		free(data->cmd2);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_prgpar	data;

	if (argc != 5)
	{
		ft_printf("arguments are not 4\n");
		return(1);
	}
	init_data(&data, argv);
	pipex(data, envp);
	data_cleanup(&data);
	return(0);
}
