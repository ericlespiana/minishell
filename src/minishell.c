/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:24:53 by tsantana          #+#    #+#             */
/*   Updated: 2024/06/05 17:08:48 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <readline/readline.h>

static void	print_envs(t_envs *envs)
{
	while (envs)
	{
		ft_printf("ENVYKEY: %s - ENVCONTENT: %s\n", envs->envkey, envs->envcontent);
		envs = envs->next;
	}
}

static void	print_mtx(t_matrix *mtx)
{
	while (mtx)
	{
		ft_printf("%s - TOKEN: %d\n", mtx->str, mtx->type);
		mtx = mtx->next;
	}
}

int	main(void)
{
	t_mini	mini;

	mini = (t_mini){0};
	mini.envars = get_envs(__environ);
	print_envs(mini.envars);
	while (1)
	{
		mini.in_ms = readline("minishell> ");
		// if (!ft_strncmp("exit", mini.in_ms, 4))
		// {
		// 	rl_clear_history();
		// 	final_free(&mini);
		// 	free_envs(mini.envars);
		// 	exit(EXIT_SUCCESS);
		// }	
		mini.in_ms = put_space_ms(mini.in_ms);
		ft_printf("%s\n", mini.in_ms);
		if (!mini.in_ms)
		{
			rl_clear_history();
			free_envs(mini.envars);
			exit(EXIT_SUCCESS);
		}
		if (mini.in_ms[0] != '\0')
		{
			mini.cmmds = parse_str(mini.in_ms);
			add_history(mini.in_ms);
			print_mtx(mini.cmmds);
		}
		final_free(&mini);
	}
	free_envs(mini.envars);
	return (0);
}
