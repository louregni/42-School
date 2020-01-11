/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:49:55 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:49:57 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"
#include "algorithm.h"
#include "utils.h"
#include "print.h"

static const t_arg		g_args[] =
{
	(t_arg){
		.size = sizeof("--color") - 1,
		.name = "--color",
	},
	(t_arg){
		.size = sizeof("--line") - 1,
		.name = "--line",
	},
	(t_arg){
		.size = sizeof("--bench") - 1,
		.name = "--bench",
	},
	(t_arg){
		.size = sizeof("--help") - 1,
		.name = "--help",
	},
	(t_arg){
		.size = sizeof("--info") - 1,
		.name = "--info",
	}
};

static unsigned int		arg_manager(int ac, char **av)
{
	int				i;
	int				save;
	unsigned int	flags;

	flags = 0;
	save = ac - 1;
	while (--ac)
	{
		i = (sizeof(g_args) / sizeof(t_arg));
		while (i--)
			if (!ft_strcmp(av[ac], g_args[i].name, g_args[i].size))
				flags |= 1 << i;
	}
	if (save && !flags)
		write(2, "\e[32m[USAGE]:\n"
		"    \e[35m--color \e[36m: enable color when printing anthill\n"
		"    \e[35m--line \e[36m: show number of lines of output\n"
		"    \e[35m--bench \e[36m: show time taken by :"
		" parsing, algorithm, printing functions\n"
		"    \e[35m--info \e[36m: show informations about parsing\n", 266);
	return (flags);
}

static int				benchmark_mode(t_parser *parser,
		t_bonus *bonus, unsigned int *nb_lines)
{
	bonus->parsing = clock();
	if (parsing(parser, bonus))
		return (-1);
	bonus->parsing = clock() - bonus->parsing;
	bonus->algorithm = clock();
	if (!(parser->data.cur_path = algorithm(&parser->data)))
		return (-1);
	bonus->algorithm = clock() - bonus->algorithm;
	bonus->print = clock();
	*nb_lines = print_anthill(&parser->data, bonus->flags);
	bonus->print = clock() - bonus->print;
	return (0);
}

static int				default_mode(t_parser *parser,
		t_bonus *bonus, unsigned int *nb_lines)
{
	if (parsing(parser, bonus))
		return (1);
	if (!(parser->data.cur_path = algorithm(&parser->data)))
		return (1);
	*nb_lines = print_anthill(&parser->data, bonus->flags);
	return (0);
}

static void				run(t_bonus *bonus, unsigned int *nb_lines)
{
	if (bonus->flags & LINE)
		show_lines(*nb_lines, bonus->flags);
	if (bonus->flags & BENCH && bonus->flags & COLOR)
		print_benchmark_color(bonus);
	else if (bonus->flags & BENCH)
		print_benchmark(bonus);
}

int						main(int ac, char **av)
{
	t_parser		parser;
	t_bonus			bonus;
	unsigned int	nb_lines;
	int				ret;

	bonus.flags = arg_manager(ac, av);
	if (bonus.flags & BENCH)
		ret = benchmark_mode(&parser, &bonus, &nb_lines);
	else
		ret = default_mode(&parser, &bonus, &nb_lines);
	if (bonus.flags & INFO && bonus.flags & COLOR)
		print_info_color(bonus.missing);
	else if (bonus.flags & INFO)
		print_info(bonus.missing);
	if (!ret)
		run(&bonus, &nb_lines);
	else
		write(2, "ERROR\n", sizeof("ERROR\n"));
	free_everything(&parser);
	return (0);
}
