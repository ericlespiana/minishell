/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:44:18 by tsantana          #+#    #+#             */
/*   Updated: 2024/06/05 15:10:35 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	free_envs(t_envs *envs)
{
	t_envs	*next;

	while (envs)
	{
		free(envs->envcontent);
		free(envs->envkey);
		next = envs->next;
		free(envs);
		envs = next;
	}
}

// void	free_envs(t_envs *envs)
// {
// 	t_envs	*temp;
//
// 	temp = NULL;
// 	while (envs)
// 	{
// 		if (!envs->next)
// 		{
// 			free(envs->envcontent);
// 			free(envs->envkey);
// 			free(envs);
// 			break ;
// 		}
// 		temp = envs;
// 		envs = envs->next;
// 		if (temp->envcontent)
// 			free(temp->envcontent);
// 		if (temp->envkey)eten
// 			free(temp->envkey);
// 		if (temp)
// 			free(temp);
// 	}
// }

static void	clear_matrix(t_matrix *mtx)
{
	t_matrix	*tmp;

	tmp = NULL;
	while (mtx)
	{
		if (!mtx->next)
		{
			free(mtx->str);
			free(mtx);
			break ;
		}
		tmp = mtx;
		mtx = mtx->next;
		if (tmp->str)
			free(tmp->str);
		if (tmp)
			free(tmp);
	}
}

void	final_free(t_mini *mini)
{
	if (mini->in_ms)
		free(mini->in_ms);
	if (mini->cmmds)
		clear_matrix(mini->cmmds);
	*mini = (t_mini){0};
}
