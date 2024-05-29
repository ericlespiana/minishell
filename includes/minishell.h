/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:25:07 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/27 20:57:14 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
#include "libft.h"

# include "../libs/libft/libft.h"

typedef struct s_envs
{
	char			*envkey;
	char			*envcontent;
	struct s_envs	*next;
}	t_envs;

typedef struct s_matrix
{
	char			*str;
	struct s_matrix	*next;
}	t_matrix;

typedef struct	s_mini
{
	char		*in_ms;
	t_envs		*envars;
	t_matrix	*cmmds;
}	t_mini;

int			aux_parse(char letter);
int			size_str(char *str);
void		final_free(t_mini *mini);

#endif
