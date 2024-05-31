/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:08:25 by tsantana          #+#    #+#             */
/*   Updated: 2024/05/30 21:08:14 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <strings.h>

// void	put_space(char *str)
// {
// 	int		i;
// 	int		space;
// 	char	*pointer;
//
// 	i = 0;
// 	space = 0;
// 	pointer = malloc((ft_strlen(str) + 1) * sizeof(char));
// 	ft_strlcpy(pointer, str, ft_strlen(pointer) + 1);
// 	while (str[i])
// 	{
// 		if (aux_parse(str[i]) == 2)
// 			space++;
// 		i++;
// 	}
// }

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
