/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:33:59 by louregni          #+#    #+#             */
/*   Updated: 2018/11/08 15:38:51 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nbr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = n * -1;
	}
	else
		nbr = n;
	if (nbr >= 10)
		ft_putnbr_fd((nbr / 10), fd);
	ft_putchar_fd((nbr % 10 + 48), fd);
}
