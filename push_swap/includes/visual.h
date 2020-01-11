/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:42:59 by louregni          #+#    #+#             */
/*   Updated: 2019/07/13 18:43:00 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <SDL.h>
# include <SDL_ttf.h>

# define WIDTH		2560
# define HEIGHT		1440
# define RENDER_W	(WIDTH / 2)
# define TEXT_C		0xffffff3f

typedef struct	s_action
{
	unsigned int	index;
	unsigned int	fc;
	struct s_action	*next;
	struct s_action	*prev;
}				t_action;

typedef struct	s_visual
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	TTF_Font		*font;
	SDL_Texture		*texture;
	SDL_Surface		*surface;
	SDL_Rect		text;
	SDL_Color		color;
	t_action		*start;
	t_action		*current;
	void			(*action[4])(t_container *box, char index);
	unsigned int	move;
	unsigned short	height;
	unsigned short	width;
	unsigned short	delay;
	unsigned short	enable;
	unsigned int	run;
}				t_visual;

void			del_list(t_container *box, t_visual *visual);
int				initializer(t_container *box, t_visual *v, int ac, char **av);
int				visualizer(t_container *box, t_visual *visual);
int				check_visual(t_visual *visual, int ac, char **av);

void			draw_stack(t_container *box, t_visual *visual);
void			paused(t_container *box, t_visual *visual);
void			play(t_container *box, t_visual *visual);

int				create_action_list(t_visual *visual);
int				bind_action(t_action *action);

#endif
