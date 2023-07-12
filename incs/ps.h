/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 14:20:12 by bfranco       #+#    #+#                 */
/*   Updated: 2023/07/12 13:09:45 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft.h"
# include <limits.h>

typedef struct s_stack
{
	t_dlist	**stack_a;
	t_dlist	**stack_b;
	t_dlist	*pivot_a;
	t_dlist	*pivot_b;
	int		len;
	t_list	**moves;
}	t_stack;

/*Operations*/
void	push(t_dlist **stack_from, t_dlist **stack_to, t_stack *info);
void	swap(t_dlist **stack, t_stack *info);
void	rotate(t_dlist **stack, t_stack *info);
void	reverse_rotate(t_dlist **stack, t_stack *info);
void	optimize_and_print(t_stack *info);

/*Utils*/
int		get_idx(t_dlist **stack, t_dlist *item);
t_dlist	*get_next(t_dlist **stack, t_dlist *item, int mode);
t_dlist	*get_small(t_dlist **stack);
t_dlist	*get_big(t_dlist **stack);
t_dlist	*get_target(t_dlist **stack, t_dlist *node);
void	print_error(char *s1, int err);

/*Sorting*/
void	index_list(t_dlist **stack);
int		sorted(t_dlist **stack, int mode);
void	sort_1_to_5(int argc, t_dlist **sa, t_dlist **sb, t_stack *info);
void	sort5(t_dlist **sa, t_dlist **sb, t_stack *info);
void	quicksort(t_stack *info);

/*Parser*/
int		parse_input(int len, char **argv, t_dlist **list);

#endif
