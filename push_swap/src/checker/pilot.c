/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pilot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:41:27 by louregni          #+#    #+#             */
/*   Updated: 2019/07/13 18:41:28 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "visual.h"

void	reverse(t_container *box, t_action *action)
{
	if (!action->fc && action->index > 0 && action->index < 4)
		swap(box, action->index);
	else if (action->fc == 1)
		push(box, (action->index == 1) ? 2 : 1);
	else if (action->fc == 2 && action->index > 0 && action->index < 4)
		revrotate(box, action->index);
	else if (action->fc == 3 && action->index > 0 && action->index < 4)
		rotate(box, action->index);
}

void	reset(t_container *box, t_visual *visual, char index)
{
	if (index & 1)
	{
		visual->move = 0;
		while (visual->current != visual->start)
		{
			reverse(box, visual->current);
			visual->current = visual->current->prev;
		}
	}
	else
	{
		while (visual->current->next->next)
		{
			visual->current = visual->current->next;
			visual->action[visual->current->fc](box, visual->current->index);
			++visual->move;
		}
	}
}

void	keydown(t_container *box, t_visual *visual)
{
	if (visual->event.key.keysym.scancode == SDL_SCANCODE_RIGHT
			&& visual->current->next->next)
	{
		visual->current = visual->current->next;
		visual->action[visual->current->fc](box, visual->current->index);
		++visual->move;
	}
	else if (visual->event.key.keysym.scancode == SDL_SCANCODE_LEFT
			&& visual->current->prev)
	{
		reverse(box, visual->current);
		visual->current = visual->current->prev;
		--visual->move;
	}
	else if (visual->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		visual->run = 2;
	else if (visual->event.key.keysym.scancode == SDL_SCANCODE_UP)
		reset(box, visual, 1);
	else if (visual->event.key.keysym.scancode == SDL_SCANCODE_DOWN)
		reset(box, visual, 2);
	draw_stack(box, visual);
}

void	paused(t_container *box, t_visual *visual)
{
	SDL_WaitEvent(&visual->event);
	if (visual->event.type == SDL_KEYUP && visual->event.key.keysym.scancode
			== SDL_SCANCODE_SPACE && visual->current->next->next)
		visual->run = 1;
	else if (visual->event.type == SDL_KEYDOWN)
		keydown(box, visual);
	else if (visual->event.type == SDL_QUIT)
		visual->run = 2;
}

void	play(t_container *box, t_visual *visual)
{
	while (!SDL_PollEvent(&visual->event))
	{
		if (visual->current->next->next)
		{
			visual->current = visual->current->next;
			visual->action[visual->current->fc](box, visual->current->index);
			++visual->move;
		}
		else
			visual->run = 0;
		draw_stack(box, visual);
		SDL_Delay(visual->delay);
	}
	if (visual->event.type == SDL_KEYUP
			&& visual->event.key.keysym.scancode == SDL_SCANCODE_SPACE)
		visual->run = 0;
	else if (visual->event.type == SDL_QUIT
			|| visual->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		visual->run = 2;
}
