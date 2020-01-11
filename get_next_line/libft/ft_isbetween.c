/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbetween.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:11:41 by louregni          #+#    #+#             */
/*   Updated: 2018/11/21 16:55:03 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isbetween(long long min, long long max, long long value)
{
	if (value >= min && value <= max)
		return (1);
	return (0);
}
