/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:41:58 by fnicolau          #+#    #+#             */
/*   Updated: 2025/08/07 20:13:10 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_empty(t_node *head)
{
	return (!head);
}

void	push(t_node **head, int data)
{
	t_node	*node;

	printf("push (%d)\n", data);
	if (!head)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->data = data;
	node->next = *head;
	*head = node;
}

int	pop(t_node **head)
{
	int		data;
	t_node	*tmp_head;

	if (is_empty(*head))
		return (-1);
	tmp_head = *head;
	data = tmp_head->data;
	*head = tmp_head->next;
	free(tmp_head);
	return (data);
}

int	peek(t_node *head)
{
	if (is_empty(head))
		return (-1);
	return (head->data);
}

void	disp_stack(t_node *node, char *title)
{
	if (title)
		printf("========= %s ==========\n", title);
	else
		printf("========= stack status ==========\n");
	if (is_empty(node))
		printf("stack is empty\n");
	else
	{
		while (node)
		{
			printf("%d -> ", node->data);
			node = node->next;
		}
		printf("NULL \n");
	}
	printf("=================================\n\n");
}

void	free_stack(t_node **head)
{
	t_node	*tmp_node;

	if (!head)
		return ;
	while (*head)
	{
		tmp_node = *head;
		*head = tmp_node->next;
		free(tmp_node);
	}
	*head = NULL;
}
// void	merge_stack(t_node **stack)
// {
// 	size_t	middle;

// 	if (start == end)
// 		return ;
// 	middle = start + (end - start) / 2;
// 	merge_stack(stack, start, middle);
// 	merge_stack(stack, middle + 1, end);
// 	merge(stack, start, middle, end);
// }

int	main(void)
{
	t_node	*head;

	head = NULL;
	// testing basic operations within a stack
	push(NULL, 2);
	disp_stack(head, NULL);
	push(&head, 3);
	disp_stack(head, NULL);
	push(&head, 5);
	disp_stack(head, NULL);
	printf("pop: %d\n", pop(&head));
	disp_stack(head, NULL);
	printf("peek: %d\n", peek(head));
	disp_stack(head, NULL);
	push(&head, 30);
	disp_stack(head, NULL);
	printf("pop: %d\n", pop(&head));
	disp_stack(head, NULL);
	push(&head, 77);
	disp_stack(head, NULL);
	printf("peek: %d\n", peek(head));
	disp_stack(head, NULL);
	printf("pop: %d\n", pop(&head));
	disp_stack(head, NULL);
	printf("peek: %d\n", peek(head));
	disp_stack(head, NULL);
	free_stack(&head);

	// sorting a stack
	push(&head, 3);
	push(&head, 5);
	push(&head, 30);
	push(&head, 77);

	disp_stack(head, "(before sorting)");
	// merge_stack(&head);
	disp_stack(head, "(after sorting)");
	return (0);
}
