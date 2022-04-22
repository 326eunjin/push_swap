/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:11:04 by ejang             #+#    #+#             */
/*   Updated: 2022/04/22 16:14:10 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
void printDQ(t_deque *DQ) // 기본 출력 문구 및 출력 위치 선정

{

t_node *temp = DQ->rear;
printf("---위---\n");

while(temp) {

printf("%3d\n", temp->data);

temp = temp->llink;

}

printf("----아래---\n");

}

int	main(int argc, char **argv)
{
	t_deque	a;
	t_deque	b;

	if (argc < 2)
		exit(0);
	init_stack(&a);
	parse_argv(&a, argv);
	if (is_dup(&a) == -1)
	{
		free_deque(&a);
		print_error();
	}
	if (sort_check(&a) == 1)
	{
		free_deque(&a);
		return (0);
	}
	printf("not sorted\n");
	make_index(&a);
	init_stack(&b);
	push_swap(&a, &b);
	printDQ(&a);
	free_deque(&a);
	free_deque(&b);
}
