/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:24:53 by tsantana          #+#    #+#             */
/*   Updated: 2024/06/19 19:33:27 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	print_envs(t_envs *envs)
// {
// 	while (envs)
// 	{
// 		ft_printf("ENVKEY: %s - ENVCONTENT: %s\n", envs->envkey, envs->envcontent);
// 		envs = envs->next;
// 	}
// }

static void	print_mtx(t_matrix *mtx)
{
	while (mtx)
	{
		ft_printf("%s - TOKEN: %d\n", mtx->str, mtx->type);
		mtx = mtx->next;
	}
}

static void	clear_exit(t_mini *mini)
{
	rl_clear_history();
	final_free(mini);
	free_envs(mini->envars);
	exit(EXIT_SUCCESS);
}

static void	if_exit(t_mini *mini)
{
	char	**matrix;
	int		j;

	j = -1;
	while (mini->in_ms[++j] == ' ');
	if (ft_memcmp(&mini->in_ms[j], "exit", 4) == 0)
	{
		matrix = ft_split(&(mini->in_ms[j]), ' ');
		j = -1;
		if (ft_strlen(matrix[0]) == 4)
		{
			while (matrix[++j] != NULL);
			if (j <= 2)
			{
				free_split(matrix);
				clear_exit(mini);
			}
			printf("exit: too many arguments\n");
		}
		free_split(matrix);
	}
}

static void	add_item(t_mini *mini)
{
	mini->cmmds = parse_str(mini->in_ms);
	add_history(mini->in_ms);
	print_mtx(mini->cmmds);
}

static void	minishell(t_mini *mini)
{
	mini->in_ms = readline("minishell> ");
	if (!mini->in_ms)
		clear_exit(mini);
	if_exit(mini);
	mini->in_ms = put_space_ms(mini->in_ms);
	if (mini->in_ms[0] != '\0')
		add_item(mini);
	final_free(mini);
}

int	main(void)
{
	t_mini	mini;

	mini = (t_mini){0};
	mini.envars = get_envs(__environ);
	//print_envs(mini.envars);
	while (1)
		minishell(&mini);
	free_envs(mini.envars);
	return (0);
}
