/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:51:38 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/08 13:01:49 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	r;

	if (n / 10 != 0)
		ft_putnbr(n / 10);
	else if (n < 0)
		ft_putchar('-');
	r = n % 10;
	if (r < 0)
		r *= -1;
	ft_putchar(r + '0');
}
