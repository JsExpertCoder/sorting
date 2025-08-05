/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:18:10 by fnicolau          #+#    #+#             */
/*   Updated: 2025/08/04 20:43:32 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// comparison-based
// Insertion
// Selection
// Quick
// Merge
// Heap

void	cpy_v(int src[], int *dst, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}
void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
void	print_complexity(char *type, int v[], size_t n, size_t cmp, size_t swp)
{
	size_t	i;

	printf("type: %s\n", type);
	printf("size: %ld\n", n);
	printf("swp: %ld\n", swp);
	printf("cmp: %ld\n", cmp);
	i = 0;
	while (i < n)
	{
		printf("%d ", v[i]);
		i++;
	}
	printf("\n");
	printf("\n");
}
void	bubble_sort(int v[], size_t n)
{
	size_t	i;
	size_t	j;
	size_t	swp;
	size_t	cmp;
	int		v2[n];

	i = 0;
	swp = 0;
	cmp = 0;
	cmp = 0;
	cpy_v(v, v2, n);
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			cmp++;
			if (v2[j] > v2[j + 1])
			{
				swp++;
				swap(&v2[j], &v2[j + 1]);
			}
			j++;
		}
		if (!swp)
			break ;
		i++;
	}
	print_complexity("bubble-sort", v2, n, cmp, swp);
}

void	selection_sort(int v[], size_t n)
{
	int	v2[n];
	size_t	i;
	size_t	j;
	size_t	cmp;
	size_t	swp;
	size_t	min;

	i = 0;
	cmp = 0;
	swp = 0;
	cpy_v(v, v2, n);
	while (i < n - 1)
	{
		min = i;
		j = i + 1;
		while (j < n)
		{
			cmp++;
			if (v2[j] < v2[min])
				min = j;
			j++;
		}
		if (v2[min] != v2[i])
		{
			swp++;
			swap(&v2[i], &v2[min]);
		}
		i++;
	}
	print_complexity("selection_sort", v2, n, cmp, swp);
}

void 	insertion_sort(int v[], size_t n)
{
	size_t	i;
	size_t	j;
	int		tmp;
	size_t	cmp;
	size_t	swp;
	int		v2[n];

	i = 1;
	cmp = 0;
	swp = 0;
	cpy_v(v, v2, n);
	while (i < n)
	{
		j = i;
		tmp = v2[i];
		while (j > 0 && tmp < v2[j - 1])
		{
			cmp++;
			swp++;
			v2[j] = v2[j - 1];
			j--;
		}
		i++;
		swp++;
		v2[j] = tmp;
	}
	print_complexity("insertion_sort", v2, n, cmp, swp);
}

// void	merge2(int array[], size_t len, int left_array[], int right_array[])
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	k;
// 	size_t	len

// 	len = sizeof(array) / sizeof(array[0]);
// 	while (k < len)
// 	{

// 		k++;
// 	}
// }

// void	merge_sort2(int array[])
// {
// 	size_t	i;
// 	size_t	len;array[i];
// 	int		middle;
// 	int		*left_array;
// 	int		*right_array;

// 	len = sizeof(array) / sizeof(array[0]);
// 	if (len == 1)
// 		return ;
// 	i = 0;array[i];
// 	middle = len / 2;
// 	left_array = malloc(middle * sizeof(int));
// 	right_array = malloc(len - middle * sizeof(int));
// 	while (i < len)
// 	{
// 		if (i < middle)
// 			left_array[i] = array[i];
// 		else
// 		{
// 			right_array[j] = array[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	merge_sort2(left_array);
// 	merge_sort2(right_array);
// 	merge2(array,left_array, right_array);
// }

void	merge(int array[], size_t start, size_t middle, size_t end)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l_a_len;
	size_t	r_a_len;
	int		*left_array;
	int		*right_array;

	i = 0;
	r_a_len = end - middle;
	l_a_len = middle - start + 1;
	left_array = malloc(l_a_len * sizeof(int));
	right_array = malloc(r_a_len * sizeof(int));
	while (i < l_a_len)
	{
		left_array[i] = array[start + i];
		i++;
	}
	j = 0;
	while (j < r_a_len)
	{
		right_array[j] = array[middle + 1 + j];
		j++;
	}
	i = 0;
	j = 0;
	k = start;
	while (i < l_a_len && j < r_a_len)
	{
		if (left_array[i] <= right_array[j])
		{
			array[k] = left_array[i];
			i++;
		}
		else
		{
			array[k] = right_array[j];
			j++;
		}
		k++;
	}
	while (i < l_a_len)
	{
		array[k] = left_array[i];
		k++;
		i++;
	}
	while (j < r_a_len)
	{
		array[k] = right_array[j];
		k++;
		j++;
	}
	free(right_array);
	free(left_array);
}

void	merge_sort(int array[], size_t start, size_t end)
{
	int	middle;
	if (start == end)
		return ;
	middle = start + (end - start) / 2;
	merge_sort(array, start, middle);
	merge_sort(array, middle + 1, end);
	merge(array, start, middle, end);
}

int main ()
{
	int	v[] = {38, 37, 8, 47, 46, 34, 33, 7, 6, 5, 4, 3, 2, 1, 32, 31, 30, 45, 44,
		43, 42, 41, 40, 39, 36, 35, 29, 21, 20, 19, 18, 17, 16, 15, 28, 27, 26, 25,
		 24, 23, 22, 14, 13, 12, 11, 10, 9, 8};

	size_t n = sizeof(v) / sizeof(v[0]);

	print_complexity("N/D", v, n, 0, 0);
	bubble_sort(v, n);
	selection_sort(v, n);
	insertion_sort(v, n);
	merge_sort(v, 0, n - 1);
	print_complexity("merge_sort", v, n, 0, 0);
	return (0);
}

// int	v[] = {0, 1, 3, 5, 5, 6, 8, 12, 12, 34, 34, 77, 87, 88, 123, 234, 324};

// hybrid:
// timsort

// key-based:
// Radix
