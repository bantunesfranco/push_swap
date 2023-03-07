/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_1_to_5.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 14:48:37 by bfranco       #+#    #+#                 */
/*   Updated: 2023/02/20 17:51:08 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ps.h"

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

void	sort3(t_dlist **sa, t_stack *info)
{
	if ((*sa)->content < (*sa)->next->content \
	&& (*sa)->content < (*sa)->next->next->content \
	&& (*sa)->next->content > (*sa)->next->next->content)
		swap(sa, info);
	if ((*sa)->content > (*sa)->next->content \
	&& (*sa)->next->content > (*sa)->next->next->content)
		swap(sa, info);
	if ((*sa)->content < (*sa)->next->content \
	&& (*sa)->content > (*sa)->next->next->content)
		reverse_rotate(sa, info);
	if ((*sa)->content > (*sa)->next->content \
	&& (*sa)->content < (*sa)->next->next->content)
		swap(sa, info);
	if ((*sa)->content > (*sa)->next->content \
	&& (*sa)->next->content < (*sa)->next->next->content)
		rotate(sa, info);
}

static void	sort4(t_dlist **sa, t_dlist **sb, t_stack *info)
{
	t_dlist	*small;

	small = get_small(sa);
	while ((*sa)->content != small->content)
	{
		if (small->index <= ft_dlstsize(*sa) / 2)
			rotate(sa, info);
		else if (small->index > ft_dlstsize(*sa) / 2)
			reverse_rotate(sa, info);
	}
	if (sorted(sa, 1))
		return ;
	push(sa, sb, info);
	sort3(sa, info);
	push(sb, sa, info);
}

void	sort5(t_dlist **sa, t_dlist **sb, t_stack *info)
{
	t_dlist	*small;

	small = get_small(sa);
	while ((*sa)->content != small->content)
	{
		if (small->index <= ft_dlstsize(*sa) / 2)
			rotate(sa, info);
		else if (small->index > ft_dlstsize(*sa) / 2)
			reverse_rotate(sa, info);
	}
	if (sorted(sa, 1))
		return ;
	push(sa, sb, info);
	sort4(sa, sb, info);
	push(sb, sa, info);
}

void	sort_1_to_5(int argc, t_dlist **sa, t_dlist **sb, t_stack *info)
{
	index_list(sa);
	if (argc == 1)
		return ;
	else if (argc == 2 && (*sa)->content > (*sa)->next->content)
		swap(sa, info);
	else if (argc == 3)
		sort3(sa, info);
	else if (argc == 4)
		sort4(sa, sb, info);
	else
		sort5(sa, sb, info);
}
