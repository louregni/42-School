/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:42:32 by louregni          #+#    #+#             */
/*   Updated: 2019/07/13 18:42:40 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	partition(int *tab, int first, int last)
{
	int i;
	int j;
	int tmp;
	int pivot;

	pivot = tab[(first + last) / 2];
	i = first - 1;
	j = last + 1;
	while (1)
	{
		while (tab[++i] < pivot)
			;
		while (tab[--j] > pivot)
			;
		if (i >= j)
			return (j);
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
	}
}

void		quicksort(int *tab, int first, int last)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(tab, first, last);
		quicksort(tab, first, pivot);
		quicksort(tab, pivot + 1, last);
	}
}
