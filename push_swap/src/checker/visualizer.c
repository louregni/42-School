/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:41:30 by louregni          #+#    #+#             */
/*   Updated: 2019/07/18 01:09:37 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "visual.h"

int				visualizer(t_container *box, t_visual *visual)
{
	SDL_SetRenderDrawColor(visual->renderer, 0, 0, 0, 255);
	SDL_RenderClear(visual->renderer);
	SDL_RenderPresent(visual->renderer);
	visual->current = visual->start;
	draw_stack(box, visual);
	while (visual->run ^ 2)
	{
		while (!visual->run)
			paused(box, visual);
		while (visual->run & 1)
			play(box, visual);
	}
	return (1);
}

static double	hue2rgb(double v1, double v2, double vh)
{
	if (vh < 0)
		vh += 1;
	if (vh > 1)
		vh -= 1;
	if ((6 * vh) < 1)
		return (v1 + (v2 - v1) * 6 * vh);
	if ((2 * vh) < 1)
		return (v2);
	if ((3 * vh) < 2)
		return (v1 + (v2 - v1) * ((2.0f / 3) - vh) * 6);
	return (v1);
}

static int		hsl2rgb(int hue, double saturation, double luminance)
{
	int			rgb;
	double		v1;
	double		v2;
	double		angle;

	if (saturation == 0)
	{
		rgb = (char)(luminance * 255);
		rgb |= (rgb << 16) | (rgb << 8);
	}
	else
	{
		angle = (double)hue / 360;
		if (luminance < 0.5)
			v2 = luminance * (1 + saturation);
		else
			v2 = (luminance + saturation) - (luminance * saturation);
		v1 = 2 * luminance - v2;
		rgb = (((char)(255. * hue2rgb(v1, v2, angle + (1.0f / 3)))) << 16)
			| (((int)(255. * hue2rgb(v1, v2, angle))) << 8)
			| ((int)(255. * hue2rgb(v1, v2, angle - (1.0f / 3))));
	}
	return (rgb);
}

static void		draw(t_stack *stack, unsigned int offset,
		t_visual *visual, int allsize)
{
	unsigned int	i;
	SDL_Rect		rect;
	t_list			*tmp;
	unsigned int	center;
	int				color;

	i = 0;
	tmp = stack->start;
	center = (HEIGHT - stack->size * visual->height) / 2;
	while (i < stack->size)
	{
		rect.w = (tmp->index + 1) * visual->width;
		rect.h = visual->height;
		rect.x = offset + ((RENDER_W - rect.w) / 2);
		rect.y = center + i * visual->height;
		color = hsl2rgb(360.0 * tmp->index / allsize, .5, .5);
		SDL_SetRenderDrawColor(visual->renderer, color & 0xff, (color >> 8)
				& 0xff, (color >> 16) & 0xff, 255);
		SDL_RenderFillRects(visual->renderer, &rect, 1);
		tmp = tmp->next;
		++i;
	}
}

void			draw_stack(t_container *box, t_visual *visual)
{
	char		str[42];

	visual->surface = TTF_RenderText_Solid(visual->font,
			SDL_itoa(visual->move, str, 10), visual->color);
	SDL_SetRenderDrawColor(visual->renderer, 0, 0, 0, 255);
	SDL_RenderClear(visual->renderer);
	draw(&box->a, 0, visual, box->a.size + box->b.size);
	draw(&box->b, RENDER_W, visual, box->a.size + box->b.size);
	visual->texture = SDL_CreateTextureFromSurface(visual->renderer,
			visual->surface);
	SDL_FreeSurface(visual->surface);
	visual->text.w = ft_strlen(str) * HEIGHT / 4;
	visual->text.x = (WIDTH - visual->text.w) / 2;
	SDL_RenderCopy(visual->renderer, visual->texture, 0, &visual->text);
	SDL_DestroyTexture(visual->texture);
	SDL_RenderPresent(visual->renderer);
}
