/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:12:28 by ckillian          #+#    #+#             */
/*   Updated: 2018/12/14 15:45:18 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_in_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (1);
	return (0);
}

int		ft_convert_base(char *str, char *base, int b, int neg)
{
	int			i;
	int			j;
	long int	total;
	int			n;

	total = 0;
	i = -1;
	n = 0;
	while (str[++i] && ft_is_in_base(str[i], base))
		n++;
	i = -1;
	while (str[++i] && ft_is_in_base(str[i], base))
	{
		j = 0;
		while (base[j] && base[j] != str[i])
			++j;
		total += j * ft_pow(b, (n - (i + 1)));
	}
	return (total * neg);
}

int		ft_check_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
			if (base[i] == base[j++])
				return (0);
	}
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int	neg;
	int	b;

	if (!str || !base)
		return (0);
	neg = (str[0] == '-') ? -1 : 1;
	if (str[0] == '+' || str[0] == '-')
		str++;
	if ((b = ft_check_base(base)) == -1 || b < 2)
		return (0);
	return (ft_convert_base(str, base, b, neg));
}
