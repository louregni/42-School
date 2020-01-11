/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:41:17 by louregni          #+#    #+#             */
/*   Updated: 2019/07/13 18:41:19 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "common.h"
#include "visual.h"

static int	init_visualizer(t_visual *visual, unsigned int nb_elem)
{
	visual->height = HEIGHT / nb_elem;
	visual->width = RENDER_W / nb_elem;
	visual->delay = 1000 / nb_elem;
	visual->color = (SDL_Color){(char)(TEXT_C >> 24), (char)(TEXT_C >> 16),
								(char)(TEXT_C >> 8), (char)TEXT_C};
	visual->text = (SDL_Rect){0, HEIGHT / 2 / 2, 0, HEIGHT / 2};
	if (!(visual->font = TTF_OpenFont("./frameworks/SDL2_ttf.framework"
					"/RobotoMono-Thin.ttf", 511)))
		write(2, "Font failed to open\n", 20);
	else if (!(visual->win = SDL_CreateWindow("Visualizer Push_Swap",
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,
				SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP)))
		write(2, "Windows creation failed :(\n", 27);
	else if (!(visual->renderer = SDL_CreateRenderer(visual->win, -1,
					SDL_RENDERER_ACCELERATED)))
		write(2, "Renderer creation failed :(\n", 28);
	else
		return (1);
	return (0);
}

int			check_visual(t_visual *visual, int ac, char **av)
{
	if (av[1][0] == '-' && av[1][1] == 'v' && !av[1][2])
	{
		if (ac == 2)
			write(2, "Not enough arguments : ./checker [optionnal -v"
				" visualizer] numbers\n", 67);
		else if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_EVENTS))
			write(2, "SDL failed to load, sorry :/\n", 29);
		else if (TTF_Init())
			write(2, "TTF failed to load, sorry :/\n", 29);
		else
		{
			visual->enable = 1;
			return (1);
		}
		SDL_Quit();
		TTF_Quit();
		return (0);
	}
	visual->enable = 0;
	return (1);
}

int			initializer(t_container *box, t_visual *visual, int ac, char **av)
{
	visual->action[0] = &swap;
	visual->action[1] = &push;
	visual->action[2] = &rotate;
	visual->action[3] = &revrotate;
	visual->start = 0;
	visual->run = 0;
	if (!create_list(box, visual->enable ? (ac - 1) : ac, visual->enable ? (av
					+ 1) : av))
		return (1);
	if (visual->enable && box->a.size > 1280)
	{
		write(2, "visualizer can handle only less than 1280 numbers\n", 50);
		visual->enable = 0;
		SDL_Quit();
		TTF_Quit();
		return (1);
	}
	if (visual->enable && !init_visualizer(visual, box->a.size))
		return (1);
	if (!create_action_list(visual))
		return (1);
	visual->current = visual->start;
	return (0);
}

t_action	*create_elem(t_action *prev, t_action *next)
{
	t_action *tmp;

	if (!(tmp = malloc(sizeof(*tmp))))
		return (0);
	tmp->prev = prev;
	tmp->next = next;
	return (tmp);
}

int			create_action_list(t_visual *visual)
{
	int			ret;
	t_action	*tmp;

	if (!(visual->start = create_elem(0, 0)))
		return (0);
	tmp = visual->start;
	if (!(tmp->next = create_elem(tmp, 0)))
		return (0);
	tmp = tmp->next;
	while ((ret = bind_action(tmp)) > 0)
	{
		if (!(tmp->next = create_elem(tmp, 0)))
			return (0);
		tmp = tmp->next;
	}
	if (ret < 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
