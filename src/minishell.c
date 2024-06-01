/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:24:53 by tsantana          #+#    #+#             */
/*   Updated: 2024/06/01 17:39:00 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <readline/readline.h>

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
		mini.in_ms = put_space_ms(mini.in_ms);
		ft_printf("%s\n", mini.in_ms);
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
