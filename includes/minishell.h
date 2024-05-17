/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:25:07 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/17 19:35:24 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

# include "../libs/libft/libft.h"

typedef struct s_matrix
{
	t_list			*words;
	struct s_matrix	*next;
}	t_matrix;

typedef struct	s_mini
{
	t_matrix	*cmmds;
}	t_mini;

#endif
