/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:25:07 by tsantana          #+#    #+#             */
/*   Updated: 2024/06/19 22:21:01 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_envs
{
	char			*envkey;
	char			*envcontent;
	struct s_envs	*next;
}	t_envs;

typedef struct s_matrix
{
	char			*str;
	int				type;
	struct s_matrix	*next;
}	t_matrix;

typedef struct s_mini
{
	char		*in_ms;
	t_envs		*envars;
	t_matrix	*cmmds;
}	t_mini;

typedef enum e_type
{
	WORD = 0,
	PIPE,
	GREATER,
	LESSER,
	DOUBLEGREATER,
	DOUBLELESSER,
}	t_type;

char		*put_space_ms(char *str);
char		**ms_split(char const *s);
char		**custom_split(char const *s, char c);
int			aux_parse(char letter);
int			size_str(char *str);
int			ft_isspace(char c);
void		final_free(t_mini *mini);
void		free_split(char **split);
void		free_envs(t_envs *envs);
t_envs		*get_envs(char **original);
t_matrix	*parse_str(char *str);

# define TRUE 1
# define FALSE 0

#endif
