/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:21:40 by tkonecny          #+#    #+#             */
/*   Updated: 2024/10/30 19:29:41 by tkonecny         ###   ########.fr       */
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

static void	idk_init(t_values *idk, char *argv[])
{
		idk->splitnosplit = true;
		idk->argv = ft_split(argv[1], ' ');
}

static void	help_function(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 2)
		sa(a);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		sort_stack(a, b);
}

static t_values	*calloc_this_shit(t_values *idk)
{
	idk = ft_calloc(1, sizeof(t_values));
	if (idk == NULL)
		exit(EXIT_FAILURE);
	return (idk);
}

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	t_values	*idk;

	a = NULL;
	b = NULL;
	idk = NULL;
	idk = calloc_this_shit(idk);
	idk->splitnosplit = false;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		free_clean(&a, &b, idk);
	else if (argc == 2)
		idk_init(idk, argv);
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
