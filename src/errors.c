/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:22:54 by tkonecny          #+#    #+#             */
/*   Updated: 2024/10/30 19:31:48 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	syntax_error(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

void	free_stack(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!a)
		return ;
	current = *a;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*a = NULL;
}

int	check_duplicates(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_clean(t_stack **a, t_stack **b, t_values *idk)
{
	int	i;

	free_stack(a);
	free_stack(b);
	if (idk && idk->splitnosplit)
	{
		i = 0;
		while (idk->argv[i])
		{
			free(idk->argv[i]);
			i++;
		}
		free(idk->argv);
		free(idk);
	}
	else
		free(idk);
	exit(EXIT_SUCCESS);
}
