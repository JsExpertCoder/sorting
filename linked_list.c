/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:43:42 by fnicolau          #+#    #+#             */
/*   Updated: 2025/08/09 17:03:35 by fnicolau         ###   ########.fr       */
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

t_node	*merge_lists(t_node *l1, t_node *l2)
{
	t_node	*head;

	if (!l1)
		return (l2);
	if (!l2)
		return (l1);
	if (l1->data <= l2->data)
	{
		head = l1;
		head->next = merge_lists(l1->next, l2);
	}
	else
	{
		head = l2;
		head->next = merge_lists(l1, l2->next);
	}
	return (head);
}

t_node	*get_middle(t_node *head)
{
	t_node	*slow;
	t_node	*fast;

	if (!head)
		return (head);
	slow = head;
	fast = head->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	return (slow);
}

void	merge_sort(t_node **head_ref)
{
	t_node	*l1;
	t_node	*l2;
	t_node	*head;
	t_node	*middle;

	if (!head_ref || !*head_ref || !(*head_ref)->next)
		return ;
	head = *head_ref;
	middle = get_middle(head);
	l1 = head;
	l2 = middle->next;
	middle->next = NULL;
	merge_sort(&l1);
	merge_sort(&l2);
	*head_ref = merge_lists(l1, l2);
}

int	main(int ac, char **av)
{
	t_node	*head;

	++av;
	(void)ac;
	head = NULL;
	while (*av)
	{
		push(&head, atoi(*av));
		av++;
	}
	disp_stack(head, "(before sorting)");
	merge_sort(&head);
	disp_stack(head, "(after sorting)");
	free_stack(&head);
	return (0);
}
/*

 compc linked_list.c && r=($(seq -77 77 | shuf | tr '\n' ' ')) && valm $r

*/