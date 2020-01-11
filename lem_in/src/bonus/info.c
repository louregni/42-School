/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:56:15 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:56:53 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"
#include "print.h"

static inline void	print_header_color(void)
{
	write(1, "\e[38;5;49m========================"
			"========================================================\n", 92);
	write(1, "|                                     \e[38;5;83mINFO"
			"                                     \e[38;5;49m|\n", 102);
	write(1, "|====================================="
			"=========================================|\n", 82);
}

void				print_info_color(unsigned int missing)
{
	print_header_color();
	write(1, "|      \e[38;5;27m{ \e[38;5;87mEnough ants : ", 43);
	missing & ANTS ? write(1, "\e[38;5;1m✗ \e[38;5;27m}", 24)
			: write(1, "\e[38;5;10m✓ \e[38;5;27m}", 25);
	write(1, "      \e[38;5;27m{ \e[38;5;87mSource node : ", 42);
	missing & SOURCE ? write(1, "\e[38;5;1m✗ \e[38;5;27m}", 24)
		: write(1, "\e[38;5;10m✓ \e[38;5;27m}", 25);
	write(1, "     \e[38;5;27m{ \e[38;5;87mSink node : ", 39);
	missing & SINK ? write(1, "\e[38;5;1m✗ \e[38;5;27m}"
			"      \e[38;5;49m|\n", 43) : write(1, "\e[38;5;10m✓ \e[38;5;27m} "
				"     \e[38;5;49m|\n", 44);
	write(1, "|          \e[38;5;27m{ \e[38;5;87mSource connections : ", 54);
	missing & SOURCE_EDGE ? write(1, "\e[38;5;1m✗ \e[38;5;27m}", 25)
			: write(1, "\e[38;5;10m✓ \e[38;5;27m}", 26);
	write(1, "         \e[38;5;27m{ \e[38;5;87mSink connections : ", 50);
	missing & SINK_EDGE ? write(1, "\e[38;5;1m✗ \e[38;5;27m} "
			"        \e[38;5;49m|\n", 46) : write(1, "\e[38;5;10m✓ "
				"\e[38;5;27m}         \e[38;5;49m|\n", 47);
	write(1, "========================================"
			"========================================\e[0m\n", 86);
}

void				print_info(unsigned int missing)
{
	write(1, "============================"
			"====================================================\n", 82);
	write(1, "|                                     INFO  "
			"                                   |\n", 82);
	write(1, "|===================================="
			"==========================================|\n", 82);
	write(1, "|      { Enough ants : ", 23);
	missing & ANTS ? write(1, "✗ }", 5) : write(1, "✓ }", 5);
	write(1, "      { Source node : ", 22);
	missing & SOURCE ? write(1, "✗ }", 5) : write(1, "✓ }", 5);
	write(1, "     { Sink node : ", 19);
	missing & SINK ?
		write(1, "✗ }      |\n", 13) : write(1, "✓ }      |\n", 13);
	write(1, "|          { Source connections : ", 34);
	missing & SOURCE_EDGE ? write(1, "✗ } ", 6) : write(1, "✓ }", 6);
	write(1, "         { Sink connections : ", 30);
	missing & SINK_EDGE ?
		write(1, "✗ }        |\n", 16) : write(1, "✓ }         |\n", 16);
	write(1, "======================="
			"=========================================================\n", 82);
}
