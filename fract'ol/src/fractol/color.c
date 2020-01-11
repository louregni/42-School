/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:55:46 by louregni          #+#    #+#             */
/*   Updated: 2019/06/23 02:51:07 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void			init_color(unsigned int color[][8])
{
	color[0][0] = 0x5534ace0;
	color[0][1] = 0x55ff793f;
	color[0][2] = 0x55ff5252;
	color[0][3] = 0x55CE1515;
	color[0][4] = 0x55474787;
	color[0][5] = 0x5540407a;
	color[0][6] = 0x552c2c54;
	color[0][7] = 0x550bf781;
	color[1][0] = 0x55a93226;
	color[1][1] = 0x559b59b6;
	color[1][2] = 0x553498db;
	color[1][3] = 0x5545b39d;
	color[1][4] = 0x552ecc71;
	color[1][5] = 0x55f5b041;
	color[1][6] = 0x55dc7633;
	color[1][7] = 0x55bdc3c7;
	color[2][0] = 0x550B0B61;
	color[2][1] = 0x5508088A;
	color[2][2] = 0x550404B4;
	color[2][3] = 0x550000FF;
	color[2][4] = 0x555858FA;
	color[2][5] = 0x555882FA;
	color[2][6] = 0x55819FF7;
	color[2][7] = 0x55CED8F6;
}

unsigned int	set_color_preview(unsigned int i)
{
	i %= 7;
	if (!i)
		return (0x006600fe);
	else if (i == 1)
		return (0x00f4f142);
	else if (i == 2)
		return (0x00b3f442);
	else if (i == 3)
		return (0x0042f486);
	else if (i == 4)
		return (0x0041dcf4);
	else if (i == 5)
		return (0x0016df4);
	else if (i == 6)
		return (0x009d41f4);
	return (0);
}
