/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 14:13:09 by bfranco       #+#    #+#                 */
/*   Updated: 2023/02/20 18:25:19 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ps.h"
#include <stdio.h>

void	print_error(char *s1, int err)
{
	errno = err;
	ft_putendl_fd(s1, 2);
	exit(err);
}

static int	init_stacks(t_stack *info)
{
	info->stack_a = (t_dlist **)ft_calloc(1, sizeof(t_dlist *));
	if (!info->stack_a)
		print_error("Error", ENOMEM);
	info->stack_b = (t_dlist **)ft_calloc(1, sizeof(t_dlist *));
	if (!info->stack_a)
		print_error("Error", ENOMEM);
	info->pivot_a = NULL;
	info->pivot_b = NULL;
	info->len = 0;
	info->moves = (t_list **)ft_calloc(1, sizeof(t_list *));
	if (!info->moves)
		print_error("Error", ENOMEM);
	return (0);
}

void	index_list(t_dlist **stack)
{
	t_dlist	*head;
	int		i;
	int		smallest;
	int		small;

	i = -1;
	smallest = get_small(stack)->content;
	while (++i < ft_dlstsize(*stack))
	{
		head = *stack;
		while (head->content != smallest)
			head = head->next;
		head->index = i;
		head = *stack;
		small = get_big(stack)->content;
		while (head)
		{
			if (head->content < small && head->content > smallest)
				small = head->content;
			head = head->next;
		}
		smallest = small;
	}
}

static char	**convert_arg(char *array)
{
	char	**arr;

	arr = ft_split(array, ' ');
	if (!arr)
		print_error("Error", ENOMEM);
	if (!arr[0])
		print_error("Error", EINVAL);
	return (arr);
}

int	main(int argc, char **argv)
{
	t_stack	info;
	int		i;
	char	**arr;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	init_stacks(&info);
	i = 1;
	while (argv[i])
	{
		arr = convert_arg(argv[i]);
		if (parse_input(ft_arrlen(arr), arr, info.stack_a) == -1)
			print_error("Error", EINVAL);
		i++;
	}
	argc = ft_dlstsize(*info.stack_a);
	info.len = argc;
	if (argc >= 1 && argc <= 5)
		sort_1_to_5(argc, info.stack_a, info.stack_b, &info);
	else
		quicksort(&info);
	optimize_and_print(&info);
	exit(EXIT_SUCCESS);
}
