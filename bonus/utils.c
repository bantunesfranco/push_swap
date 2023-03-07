/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 14:21:30 by bfranco       #+#    #+#                 */
/*   Updated: 2023/02/20 13:01:27 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

void	del(void *content)
{
	free(content);
}

void	clear_stacks(t_stack *info)
{
	ft_dlstclear(info->stack_a);
	ft_dlstclear(info->stack_b);
}

int	sorted(t_dlist **stack, int mode)
{
	t_dlist	*head;

	if (mode == 1 && *stack)
	{
		head = *stack;
		while (head->next)
		{
			if (head->content > head->next->content)
				return (0);
			head = head->next;
		}
	}
	if (mode == -1 && *stack)
	{
		head = *stack;
		while (head->next)
		{
			if (head->content < head->next->content)
				return (0);
			head = head->next;
		}
	}
	return (1);
}

void	print_error(char *s1, int err)
{
	errno = err;
	ft_putendl_fd(s1, 2);
	exit(err);
}
