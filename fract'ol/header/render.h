/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 07:41:56 by louregni          #+#    #+#             */
/*   Updated: 2019/06/23 02:54:00 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include <pthread.h>

# define NB_THREAD 20
# define NB_FRACTAL 8
# define WIDTH 2560
# define HEIGHT 1250
# define IMG_W 1000
# define IMG_H 1000
# define RENDER 500
# define POS1_W ((WIDTH / 2) - (IMG_W / 2))
# define POS1_H ((HEIGHT / 2) - (IMG_H / 2))
# define POS2_W ((POS1_W / 2) - (RENDER / 2))
# define POS2_H (POS1_H + (RENDER / 2))
# define POS3_W ((WIDTH / 2) + (IMG_W / 2) + 125)
# define LIMIT (IMG_H / NB_THREAD)

typedef struct		s_complex
{
	long double		r;
	long double		i;
}					t_complex;

typedef struct		s_info
{
	int				(*fractal[NB_FRACTAL])(struct s_info *info,
			unsigned int x, unsigned int y);
	t_complex		mouse;
	t_complex		cord;
	unsigned int	iteration;
	long double		zoom;
	unsigned int	color[3][8];
	unsigned int	c;
	unsigned int	i;
	unsigned int	cur;
	unsigned int	*buffer;
	unsigned int	increment;
	unsigned int	lock;
}					t_info;

typedef struct		s_render
{
	void			*mlx;
	void			*win;
	void			*img[3];
	void			*buffer[2];
	pthread_t		thread[NB_THREAD];
	t_complex		cord[2][NB_FRACTAL];
	t_complex		fractal[2][NB_FRACTAL];
	long double		zoom[2][NB_FRACTAL];
	unsigned int	iteration[2][NB_FRACTAL];
	t_info			info;
}					t_render;

typedef struct		s_view
{
	t_info			*info;
	unsigned int	id;
}					t_view;

typedef struct		s_box
{
	t_render		render;
	t_view			settings[NB_THREAD];
	t_info			info;
}					t_box;

/*
** Initializer
*/

void				init_thread(t_box *box);
void				init_fractal(t_render *render);
void				init_imagin(t_render *render);
void				init_real(t_render *render);
void				init_cord(t_render *render);
void				init_zoom(t_render *render);
void				init_iteration(t_render *render);
void				set_fractal(t_box *box);
void				set_fractal_preview(t_box *box, unsigned int i);
int					initialize(t_box *box);

/*
** Render
*/

int					rendering(t_box *box);
int					thread_caller(t_box *box);
int					close_render(t_render *render);

/*
** Event
*/

int					mouse(int button, int x, int y, t_box *box);
int					mouse_pos(int x, int y, t_box *box);
void				gesture_fractal(int button, int x, int y, t_box *box);
void				gesture_prev(t_box *box);
void				gesture_next(t_box *box);
int					key(int key, t_box *box);
int					check_fractal(t_box *box, char *str);

/*
** Draw
*/

void				draw_render(t_box *box);
void				draw_button(t_box *box);
void				draw_fractal(t_info *info, unsigned int *buffer,
		int (*fractal)(t_info *info, unsigned int x, unsigned int y));
void				draw(t_box *box);

/*
** Color
*/

void				init_color(unsigned int color[][8]);
unsigned int		set_color_preview(unsigned int i);

#endif
