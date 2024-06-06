/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:05:58 by tsantana          #+#    #+#             */
/*   Updated: 2024/06/06 14:10:24 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char	c)
{
	if (c == '\f')
		return (1);
	else if (c == '\n')
		return (2);
	else if (c == '\r')
		return (3);
	else if (c == '\t')
		return (4);
	else if (c == '\v')
		return (5);
	else
		return (0);
}
