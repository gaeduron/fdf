/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:14:05 by gduron            #+#    #+#             */
/*   Updated: 2017/04/14 18:52:59 by gduron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	return ((c == '\n' || c == '\t' || c == ' '\
				|| c == '\r' || c == '\v' || c == '\f') ? 1 : 0);
}
