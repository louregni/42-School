/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 04:38:20 by louregni          #+#    #+#             */
/*   Updated: 2019/12/16 04:38:21 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H
# include <time.h>

# define COLOR 1
# define LINE  2
# define BENCH 4
# define HELP  8
# define INFO  16
# define ANTS 1
# define SOURCE 2
# define SINK 4
# define SOURCE_EDGE 8
# define SINK_EDGE 16

typedef	struct	s_bonus
{
	clock_t			parsing;
	clock_t			algorithm;
	clock_t			print;
	unsigned int	flags;
	unsigned int	missing;
}				t_bonus;

void			print_benchmark(t_bonus *bonus);
void			show_lines(unsigned int lines, unsigned int flags);
int				parsing(t_parser *parser, t_bonus *bonus);
int				check_info(t_parser *parser, t_bonus *bonus);
void			print_info(unsigned int missing);
void			print_info_color(unsigned int missing);
void			print_benchmark(t_bonus *bonus);
void			print_benchmark_color(t_bonus *bonus);
void			leave_color(t_id *id, t_name *name);
void			classic(t_id *id, t_name *name);
void			leave_color(t_id *id, t_name *name);
void			enter_color(t_id *id, t_name *name);
void			print_leave(t_id *id, t_name *name, unsigned int flags);
void			print_enter(t_id *id, t_name *name, unsigned int flags);
void			print_ant(t_id *id, t_name *name);

#endif
