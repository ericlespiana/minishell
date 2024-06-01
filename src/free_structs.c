/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:44:18 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/31 22:21:00 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

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
