/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:56:08 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:56:09 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"
#include "print.h"
#include "utils.h"

static void			print_header_color(void)
{
	write(1, "\e[38;5;49m==============================="
			"=================================================\n", 91);
	write(1, "|                                 \e[38;5;83mBENCHMARKING"
			"                                 \e[38;5;49m|\n", 101);
	write(1, "|==============================="
			"===============================================|\n", 81);
}

static void			print_header(void)
{
	write(1, "==============================="
			"=================================================\n", 81);
	write(1, "|                                 BENCHMARKING"
			"                                 |\n", 81);
	write(1, "|==============================="
			"===============================================|\n", 81);
}

void				print_benchmark(t_bonus *bonus)
{
	t_id	result;

	print_header();
	ft_itoa(bonus->parsing / (CLOCKS_PER_SEC / 1000000.), &result);
	write(1, "|                         ", 26 - (result.size / 2));
	write(1, "  { Time took by parsing : ", 27);
	write(1, result.ptr, result.size);
	write(1, " μs }                      ",
		27 - ((result.size / 2) + result.size % 2));
	ft_itoa(bonus->algorithm / (CLOCKS_PER_SEC / 1000000.), &result);
	write(1, "|\n|                         ", 28 - (result.size / 2));
	write(1, "{ Time took by algorithm : ", 27);
	write(1, result.ptr, result.size);
	write(1, " μs }                    ",
		27 - ((result.size / 2) + result.size % 2));
	ft_itoa(bonus->print / (CLOCKS_PER_SEC / 1000000.), &result);
	write(1, "|\n|                       ", 28 - result.size / 2);
	write(1, " { Time took by printing : ", 27);
	write(1, result.ptr, result.size);
	write(1, " μs }                     ",
		27 - ((result.size / 2) + result.size % 2));
	write(1, "|\n", 2);
	write(1, "=============================="
			"==================================================\n", 81);
}

static inline void	print_end(void)
{
	write(1, "\e[38;5;49m|\n=============================="
			"==================================================\n\e[0m", 97);
}

void				print_benchmark_color(t_bonus *bonus)
{
	t_id	r;

	print_header_color();
	ft_itoa(bonus->parsing / (CLOCKS_PER_SEC / 1000000.), &r);
	write(1, "|                         ", 26 - (r.size / 2));
	write(1, "  \e[38;5;27m{ \e[38;5;87mTime took by parsing"
			" : \e[38;5;118m", 58);
	write(1, r.ptr, r.size);
	write(1, " μs \e[38;5;27m}                      ",
		37 - ((r.size / 2) + r.size % 2));
	ft_itoa(bonus->algorithm / (CLOCKS_PER_SEC / 1000000.), &r);
	write(1, "\e[38;5;49m|\n|                         ", 38 - (r.size / 2));
	write(1, "\e[38;5;27m{ \e[38;5;87mTime took by algorithm"
		" : \e[38;5;118m", 58);
	write(1, r.ptr, r.size);
	write(1, " μs \e[38;5;27m}                    ",
			37 - ((r.size / 2) + r.size % 2));
	ft_itoa(bonus->print / (CLOCKS_PER_SEC / 1000000.), &r);
	write(1, "\e[38;5;49m|\n|                       ", 38 - r.size / 2);
	write(1, " \e[38;5;27m{ \e[38;5;87mTime took by printing "
		": \e[38;5;118m", 58);
	write(1, r.ptr, r.size);
	write(1, " μs \e[38;5;27m}                    ",
			37 - ((r.size / 2) + r.size % 2));
	print_end();
}
