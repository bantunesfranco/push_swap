/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/06 13:33:55 by bfranco       #+#    #+#                 */
/*   Updated: 2023/02/21 13:16:09 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ps.h"

t_dlist	*get_big(t_dlist **stack)
{
	t_dlist	*head;
	t_dlist	*big;

	head = *stack;
	big = head;
	while (head)
	{
		if (head->content > big->content)
			big = head;
		head = head->next;
	}
	return (big);
}

t_dlist	*get_small(t_dlist **stack)
{
	t_dlist	*head;
	t_dlist	*small;

	head = *stack;
	small = head;
	while (head)
	{
		if (head->content < small->content)
			small = head;
		head = head->next;
	}
	return (small);
}

t_dlist	*get_next(t_dlist **stack, t_dlist *item, int mode)
{
	t_dlist	*head;
	t_dlist	*next;

	head = *stack;
	next = item;
	while (head)
	{
		if (mode == 1 && head->index == item->index + 1 \
		&& item->index + 1 < ft_dlstsize(*stack))
			next = head;
		if (mode == -1 && head->index == item->index - 1 \
		&& item->index - 1 >= 0)
			next = head;
		head = head->next;
	}
	return (next);
}

int	get_idx(t_dlist **stack, t_dlist *item)
{
	int		idx;
	t_dlist	*head;

	head = *stack;
	idx = 0;
	while (head && head->next && head->content != item->content)
	{
		idx++;
		head = head->next;
	}
	return (idx);
}

t_dlist	*get_target(t_dlist **stack, t_dlist *node)
{
	t_dlist	*small;
	t_dlist	*head;

	head = *stack;
	small = get_big(stack);
	if (node->content <= get_small(stack)->content)
		return (get_small(stack));
	if (node->content >= get_big(stack)->content)
		return (get_small(stack));
	while (head)
	{
		if (head->content > node->content && head->content < small->content)
			small = head;
		head = head->next;
	}
	return (small);
}
