/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 10:37:05 by bfranco       #+#    #+#                 */
/*   Updated: 2023/02/21 15:22:49 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ps.h"

static void	get_to_pos(t_dlist **stack, t_dlist *new, t_stack *info)
{
	t_dlist	*target;
	int		idx;

	target = get_target(stack, new);
	idx = get_idx(stack, target);
	while ((*stack)->content != target->content)
	{
		if (idx <= ft_dlstsize(*stack) / 2)
			rotate(stack, info);
		else if (idx > ft_dlstsize(*stack) / 2)
			reverse_rotate(stack, info);
	}
}

t_dlist	*get_pivot(t_dlist **stack, t_stack *info)
{
	t_dlist	*head;
	int		i;
	int		size;

	i = 0;
	head = *stack;
	if (info->len <= 100)
		size = ft_dlstsize(*stack) / 4;
	else if (info->len <= 500)
		size = ft_dlstsize(*stack) / 6;
	else
		size = ft_dlstsize(*stack) / 6;
	while (head->index != size)
		head = head->next;
	return (head);
}

void	partition_b(t_dlist **sa, t_dlist **sb, t_stack *info)
{
	t_dlist	*big;
	int		idx;
	int		idx2;

	while (*sb)
	{
		big = get_big(sb);
		idx = get_idx(sb, big);
		idx2 = get_idx(sb, get_next(sb, big, -1));
		if ((idx2 < idx && idx <= ft_dlstsize(*sb) / 2) \
		|| (idx2 > idx && idx > ft_dlstsize(*sb) / 2))
		{
			big = get_next(sb, big, -1);
			idx = idx2;
		}
		while ((*sb)->content != big->content)
		{
			if (idx <= ft_dlstsize(*sb) / 2)
				rotate(sb, info);
			else if (idx > ft_dlstsize(*sb) / 2)
				reverse_rotate(sb, info);
		}
		get_to_pos(sa, *sb, info);
		push(sb, sa, info);
	}
}

void	partition_a(t_dlist **sa, t_dlist **sb, t_stack *info)
{
	info->pivot_a = get_pivot(sa, info);
	while (!sorted(sa, 1) || ft_dlstsize(*sa) > 5)
	{
		if ((*sa)->content > info->pivot_a->content)
			rotate(sa, info);
		else if ((*sa)->content < info->pivot_a->content)
		{
			push(sa, sb, info);
			if ((*sb)->next && (*sb)->index <= (info->pivot_a->index / 2))
				rotate(sb, info);
		}
		if (get_small(sa)->content == info->pivot_a->content)
			break ;
		if ((*sa)->content == info->pivot_a->content)
			rotate(sa, info);
	}
	if (ft_dlstsize(*sa) == 5)
		sort5(sa, sb, info);
	if (!sorted(sa, 1))
	{
		index_list(sa);
		partition_a(sa, sb, info);
	}
	return ;
}

void	quicksort(t_stack *info)
{
	t_dlist	**stack_a;
	t_dlist	**stack_b;

	stack_a = info->stack_a;
	stack_b = info->stack_b;
	if (sorted(stack_a, 1))
		return ;
	index_list(stack_a);
	partition_a(stack_a, stack_b, info);
	partition_b(stack_a, stack_b, info);
	get_to_pos(stack_a, get_small(stack_a), info);
}
