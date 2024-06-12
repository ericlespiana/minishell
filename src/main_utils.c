/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:08:25 by tsantana          #+#    #+#             */
/*   Updated: 2024/06/12 18:06:23 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/history.h>
#include <strings.h>

int	its_onlyspace(t_mini *mini)
{
	int		value;
	int		i;
	char	*ptr;

	i = 0;
	value = 0;
	ptr = mini->in_ms;
	while (ptr[i])
	{
		if (ft_isspace(ptr[i]))
			value++;
		i++;
	}
	if (value == 0)
	{
		add_history(ptr);
		return (1);
	}
	return (0);
}

int	verify_parse(t_mini **mini)
{
	int			i;
	char	*temp;

	i = 0;
	temp = (*mini)->in_ms;
	while (temp && ft_isspace(temp[i]) != 0)
		i++;
	if (temp[i] == '|')
	{
		add_history((*mini)->in_ms);
		return (ms_error(0), 1);
	}
	i = ft_strlen(temp) - 1;
	while (i > 0 && ft_isspace(temp[i]))
		i--;
	if (aux_parse(temp[i]) == 2)
	{
		add_history((*mini)->in_ms);
		return (ms_error(1), 1);
	}
	return (0);
}

int	aux_parse(char letter)
{
	if (letter == ' ')
		return (1);
	if (letter == '|' || letter == '&' || letter == '<' || letter == '>')
		return (2);
	return (0);
}

int	size_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] && aux_parse(str[i]) == 0)
		i++;
	return (i);
}
