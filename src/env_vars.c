/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:56:23 by tsantana          #+#    #+#             */
/*   Updated: 2024/06/03 22:14:04 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

static t_envs	*put_ls_colors(char *str)
{
	t_envs	*env;
	int		equal;
	char	*str1;

	str1 = ft_strchr(str, '=');
	equal = str1 - str;
	env = malloc(sizeof(t_envs));
	env->envcontent	= ft_strdup(++str1);
	env->envkey = ft_substr(str, 0, equal);
	env->next = NULL;
	return (env);
}

static t_envs	*make_env_node(char	**envs_split)
{
	t_envs	*envs;

	envs = malloc(sizeof(t_envs));
	envs->envkey = ft_strdup(envs_split[0]);
	envs->envcontent = ft_strdup(envs_split[1]);
	envs->next = NULL;
	free_split(envs_split);
	return (envs);
}

t_envs	*get_envs(char **original)
{
	int		i;
	t_envs	*envs;
	t_envs	*head;
	char	**split_env;

	i = 1;
	envs = NULL;
	if (!envs)
		envs = make_env_node(ft_split(original[0], '='));
	head = envs;
	while (original[i])
	{
		if (ft_strncmp("LS_COLORS", original[i], 9) != 0)
		{
			split_env = ft_split(original[i], '=');
			envs->next = make_env_node(split_env);
			envs = envs->next;
		}
		else
		{
			envs->next = put_ls_colors(original[i]);
			envs = envs->next;
		}
		i++;
	}
	return (head);
}
