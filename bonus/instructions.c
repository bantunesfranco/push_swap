/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/17 17:24:33 by bfranco       #+#    #+#                 */
/*   Updated: 2023/02/20 13:30:31 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

static void	exec_instructions2(t_list *head, t_stack *info)
{
	if (!ft_strncmp(head->content, "rr\n", 3))
	{
		rotate(info->stack_a);
		rotate(info->stack_b);
	}
	else if (!ft_strncmp(head->content, "ss\n", 3))
	{
		swap(info->stack_a);
		swap(info->stack_b);
	}
	else if (!ft_strncmp(head->content, "rra\n", 4))
		reverse_rotate(info->stack_a);
	else if (!ft_strncmp(head->content, "rrb\n", 4))
		reverse_rotate(info->stack_b);
	else if (!ft_strncmp(head->content, "rrr\n", 4))
	{
		reverse_rotate(info->stack_a);
		reverse_rotate(info->stack_b);
	}
}

void	exec_instructions(t_list **moves, t_stack *info)
{
	t_list		*head;

	head = *moves;
	while (head)
	{
		if (!ft_strncmp(head->content, "pa\n", 3))
			push(info->stack_b, info->stack_a);
		else if (!ft_strncmp(head->content, "pb\n", 3))
			push(info->stack_a, info->stack_b);
		else if (!ft_strncmp(head->content, "sa\n", 3))
			swap(info->stack_a);
		else if (!ft_strncmp(head->content, "sb\n", 3))
			swap(info->stack_b);
		else if (!ft_strncmp(head->content, "ra\n", 3))
			rotate(info->stack_a);
		else if (!ft_strncmp(head->content, "rb\n", 3))
			rotate(info->stack_b);
		else
			exec_instructions2(head, info);
		head = head->next;
	}
	ft_lstclear(moves, &del);
	free(moves);
}
