/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:21:40 by tkonecny          #+#    #+#             */
/*   Updated: 2024/10/25 11:13:07 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// static void	printstack(t_stack *a)
// {
// 	while (a)
// 	{
// 		ft_printf("%d\n", (int)a->nbr);
// 		a = a->next;
// 	}
// }

static void	help_function(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 2)
		sa(a);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		sort_stack(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	t_values	*idk;

	a = NULL;
	b = NULL;
	idk = ft_calloc(1, sizeof(t_values));
	idk->splitnosplit = false;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		free_clean(&a, &b, idk);
	else if (argc == 2)
	{
		idk->splitnosplit = true;
		idk->argv = ft_split(argv[1], ' ');
	}
	else
		idk->argv = argv + 1;
	if (!ft_stack_init(&a, idk->argv))
	{
		ft_printf("Error\n");
		free_clean(&a, &b, idk);
	}
	if (!stack_sorted(a))
		help_function(&a, &b);
	free_clean(&a, &b, idk);
}
