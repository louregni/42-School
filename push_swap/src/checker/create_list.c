/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:41:13 by louregni          #+#    #+#             */
/*   Updated: 2019/07/13 18:41:14 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"
#include "visual.h"

void		free_action(t_action *action)
{
	t_action *tmp;

	while (action)
	{
		tmp = action->next;
		free(action);
		action = tmp;
	}
}

void		exit_sdl(t_visual *visual)
{
	if (visual->win)
	{
		if (visual->renderer)
			SDL_DestroyRenderer(visual->renderer);
		if (visual->font)
			TTF_CloseFont(visual->font);
		SDL_DestroyWindow(visual->win);
	}
	SDL_Quit();
	TTF_Quit();
}

void		del_list(t_container *box, t_visual *visual)
{
	del(box->a.start);
	del(box->b.start);
	free_action(visual->start);
	if (visual->enable)
		exit_sdl(visual);
}
