/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 13:06:07 by bfranco       #+#    #+#                 */
/*   Updated: 2023/02/20 13:39:45 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

static int	init_stacks(t_stack *info)
{
	info->stack_a = (t_dlist **)ft_calloc(1, sizeof(t_dlist *));
	if (!info->stack_a)
		print_error("Error", ENOMEM);
	info->stack_b = (t_dlist **)ft_calloc(1, sizeof(t_dlist *));
	if (!info->stack_b)
		print_error("Error", ENOMEM);
	return (0);
}

static void	convert_arg(char **argv, t_stack *info)
{
	char	**arr;
	int		i;

	i = 0;
	while (argv[++i])
	{
		arr = ft_split(argv[i], ' ');
		if (!arr)
			print_error("Error", ENOMEM);
		if (!arr[0])
			print_error("Error", EINVAL);
		if (parse_input(ft_arrlen(arr), arr, info->stack_a) == -1)
			print_error("Error", EINVAL);
	}
}

int	main(int argc, char **argv)
{
	t_stack	info;
	t_list	**moves;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	init_stacks(&info);
	convert_arg(argv, &info);
	if (sorted(info.stack_a, 1) && !*info.stack_b)
	{
		clear_stacks(&info);
		exit(EXIT_SUCCESS);
	}
	argc = ft_dlstsize(*info.stack_a);
	moves = read_instructions();
	exec_instructions(moves, &info);
	if (sorted(info.stack_a, 1))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_stacks(&info);
	exit(EXIT_SUCCESS);
}
