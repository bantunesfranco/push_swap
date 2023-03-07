/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 13:51:05 by bfranco       #+#    #+#                 */
/*   Updated: 2023/02/20 13:32:40 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

void	push(t_dlist **stack_from, t_dlist **stack_to)
{
	t_dlist	*head_to;

	head_to = NULL;
	if (*stack_from)
	{
		head_to = *stack_to;
		*stack_to = *stack_from;
		*stack_from = (*stack_from)->next;
		if (*stack_from)
			(*stack_from)->prev = NULL;
		(*stack_to)->next = head_to;
		if ((*stack_to)->next)
			(*stack_to)->next->prev = *stack_to;
	}
}

void	swap(t_dlist **stack)
{
	t_dlist	*head;

	head = NULL;
	if (*stack && ft_dlstsize(*stack) > 1)
	{
		head = *stack;
		*stack = (*stack)->next;
		head->next = (*stack)->next;
		head->prev = *stack;
		(*stack)->next = head;
		(*stack)->prev = NULL;
		if ((*stack)->next->next)
			(*stack)->next->next->prev = (*stack)->next;
	}
}

void	rotate(t_dlist **stack)
{
	t_dlist	*head;

	head = NULL;
	if (*stack && ft_dlstsize(*stack) > 1)
	{
		head = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		ft_dlstadd_back(stack, head);
		head->next = NULL;
	}
}

void	reverse_rotate(t_dlist **stack)
{
	t_dlist	*last;

	if (*stack && ft_dlstsize(*stack) > 1)
	{
		last = ft_dlstlast(*stack);
		if (last->prev)
			last->prev->next = NULL;
		last->prev = NULL;
		ft_dlstadd_front(stack, last);
	}
}
