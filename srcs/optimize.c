/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimize.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:46:06 by bfranco       #+#    #+#                 */
/*   Updated: 2023/02/13 17:48:53 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ps.h"

static void	print_moves(t_list **moves)
{
	t_list	*head;

	head = *moves;
	while (head)
	{
		ft_printf("%s\n", head->content);
		head = head->next;
	}
}

static void	optimize2(t_list *head)
{
	t_list	*node;

	if ((!ft_strncmp(head->content, "rra", 3) \
	&& !ft_strncmp(head->next->content, "rrb", 3)) \
	|| (!ft_strncmp(head->content, "rrb", 3) \
	&& !ft_strncmp(head->next->content, "rra", 3)))
	{
		head->content = "rrr";
		node = head->next;
		free(node);
		head->next = head->next->next;
	}
}

static void	optimize(t_list **moves)
{
	t_list	*head;
	t_list	*node;

	head = *moves;
	while (head->next)
	{
		if ((!ft_strncmp(head->content, "ra", 3) \
		&& !ft_strncmp(head->next->content, "rb", 3)) \
		|| (!ft_strncmp(head->content, "rb", 3) \
		&& !ft_strncmp(head->next->content, "ra", 3)))
		{
			head->content = "rr";
			node = head->next;
			free(node);
			head->next = head->next->next;
		}
		optimize2(head);
		head = head->next;
	}
}

void	optimize_and_print(t_stack *info)
{
	ft_dlstclear(info->stack_a);
	ft_dlstclear(info->stack_b);
	if (*info->moves)
	{
		optimize(info->moves);
		print_moves(info->moves);
	}
	ft_dlstclear((t_dlist **)info->moves);
}
