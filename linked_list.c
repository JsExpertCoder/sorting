/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:41:58 by fnicolau          #+#    #+#             */
/*   Updated: 2025/08/08 14:47:02 by fnicolau         ###   ########.fr       */
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
// Utility function to split a linked list into two halves
void split_list(t_node *source, t_node **front, t_node **back) {
    t_node *slow;
    t_node *fast;

    if (!source || !source->next) {
        *front = source;
        *back = NULL;
        return;
    }

    slow = source;
    fast = source->next;

    // Move fast by 2 and slow by 1
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL; // split the list
}

// Merge two sorted lists
t_node *sorted_merge(t_node *a, t_node *b) {
    t_node *result = NULL;

    if (!a) return b;
    if (!b) return a;

    if (a->data <= b->data) {
        result = a;
        result->next = sorted_merge(a->next, b);
    } else {
        result = b;
        result->next = sorted_merge(a, b->next);
    }
    return result;
}

// Merge sort for linked list
void merge_sort(t_node **head_ref) {
    t_node *a;
    t_node *b;
    t_node *head;

    if (!head_ref) return;
	head = *head_ref;
	if (!head || !head->next) return ;

    // 1. Split
    split_list(head, &a, &b);

    // 2. Sort each half
    merge_sort(&a);
    merge_sort(&b);

    // 3. Merge
    *head_ref = sorted_merge(a, b);
}

int	main(void)
{
	t_node	*head;

	head = NULL;
	// testing basic operations within a stack
	// push(NULL, 2);
	// disp_stack(head, NULL);
	// push(&head, 3);
	// disp_stack(head, NULL);
	// push(&head, 5);
	// disp_stack(head, NULL);
	// disp_stack(head, NULL);
	// disp_stack(head, NULL);
	// push(&head, 30);
	// disp_stack(head, NULL);
	// disp_stack(head, NULL);
	// push(&head, 77);
	// disp_stack(head, NULL);
	// disp_stack(head, NULL);
	// disp_stack(head, NULL);
	// disp_stack(head, NULL);
	// free_stack(&head);

	// sorting a stack
	push(&head, 3);
	push(&head, 5);
	push(&head, 30);
	push(&head, 77);

	disp_stack(head, "(before sorting)");
	merge_sort(&head);
	disp_stack(head, "(after sorting)");
	free_stack(&head);

	return (0);
}
