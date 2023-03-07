/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 11:38:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/02/20 13:08:05 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

static void	check_list(t_dlist **list)
{
	t_dlist		*node;
	t_dlist		*node2;

	node = *list;
	while (node->next)
	{
		node2 = node->next;
		while (node2)
		{
			if (node->content == node2->content)
			{
				ft_dlstclear(list);
				print_error("Error", EINVAL);
			}
			node2 = node2->next;
		}
		node = node->next;
	}
}

int	parse_input(int len, char **arr, t_dlist **list)
{
	int			i;
	long int	nb;
	t_dlist		*node;

	i = -1;
	while (++i < len)
	{
		if (!ft_isnumber(arr[i]))
			return (ft_dlstclear(list), -1);
		nb = ft_atol(arr[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (ft_dlstclear(list), -1);
		node = ft_dlstnew(nb);
		if (!node)
			print_error("Error", ENOMEM);
		ft_dlstadd_back(list, node);
	}
	check_list(list);
	ft_free_arr(arr);
	return (0);
}

static t_list	*is_valid_op(char *line)
{
	int			i;
	const char	*ops[11] = {"pa\n", "pb\n", "sa\n", "sb\n", "ss\n", \
	"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};

	i = -1;
	while (++i < 11)
	{
		if (!ft_strncmp(line, ops[i], ft_strlen(ops[i]) + 1))
			return (ft_lstnew(line));
	}
	print_error("Error", EINVAL);
	return (NULL);
}

t_list	**read_instructions(void)
{
	char		*line;
	t_list		**moves;
	t_list		*node;

	moves = (t_list **)ft_calloc(1, sizeof(t_list *));
	if (!moves)
		print_error("Error", ENOMEM);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		node = is_valid_op(line);
		if (!node)
			print_error("Error", ENOMEM);
		ft_lstadd_back(moves, node);
	}
	return (moves);
}
