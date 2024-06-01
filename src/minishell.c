/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:24:53 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/31 22:23:37 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	search_type(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '|' && !str[i + 1])
		return (PIPE);
	else if (str[i] == '>' && !str[i + 1])
		return (GREATER);
	else if (str[i] == '<' && !str[i + 1])
		return (LESSER);
	else if (str[i] == '<' && str[i + 1] == '<')
		return (DOUBLELESSER);
	else if (str[i] == '>' && str[i + 1] == '>')
		return (DOUBLEGREATER);
	else
		return (WORD);
}

static t_matrix	*create_mtx(char *str)
{
	t_matrix	*ms;

	ms = malloc(sizeof(t_matrix));
	if (!ms)
		return (NULL);
	ms->str = ft_strdup(str);
	ms->type = search_type(str);
	ms->next = NULL;
	return (ms);
}

static t_matrix	*parse_str(char *str)
{
	char		**parse_str;
	t_matrix	*mtx;
	t_matrix	*head;
	int			i;

	if (!str)
		return (NULL);
	i = 0;
	mtx = NULL;
	parse_str = custom_split(str, ' ');
	mtx = create_mtx(parse_str[i]);
	if (!mtx)
		return (NULL);
	head = mtx;
	i++;
	while (parse_str[i])
	{
		mtx->next = create_mtx(parse_str[i]);
		mtx = mtx->next;
		i++;
	}
	free_split(parse_str);
	return (head);
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
	while (1)
	{
		mini.in_ms = readline("minishell> ");
		if (!mini.in_ms)
		{
			rl_clear_history();
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
	return (0);
}
