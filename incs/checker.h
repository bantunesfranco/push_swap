/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 12:58:23 by bfranco       #+#    #+#                 */
/*   Updated: 2023/03/10 15:43:17 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <libft.h>
# include <limits.h>

typedef struct s_stack
{
	t_dlist	**stack_a;
	t_dlist	**stack_b;
}	t_stack;

/*Operations*/
void	push(t_dlist **stack_from, t_dlist **stack_to);
void	swap(t_dlist **stack);
void	rotate(t_dlist **stack);
void	reverse_rotate(t_dlist **stack);

/*Parsing*/
int		parse_input(int len, char **arr, t_dlist **list);
t_list	**read_instructions(void);

/*Sorting*/
void	exec_instructions(t_list **moves, t_stack *info);
int		sorted(t_dlist **stack, int mode);

/*Utils*/
void	del(void *content);
void	clear_stacks(t_stack *info);
void	print_error(char *s1, int err);

#endif