/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:36:16 by tsantana          #+#    #+#             */
/*   Updated: 2024/06/06 15:51:30 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	ms_error(int type)
{
	if (type == 0)
		ft_printf("parse error near `|'\n");
	else if (type == 1)
		ft_printf("parse error at the end\n");
}
