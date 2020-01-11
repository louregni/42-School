/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 01:00:25 by louregni          #+#    #+#             */
/*   Updated: 2019/02/01 01:02:28 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_revert(char *str, int count)
{
	char	tmp;
	char	*save;

	save = str;
	while (&str[count] >= save)
	{
		tmp = *save;
		*save = str[count];
		str[count] = tmp;
		++save;
		--count;
	}
}
