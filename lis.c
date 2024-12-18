#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int *lst_fill(int *arr, int length, int val)
{
	int i;

	i = 0;
	while (i++ < length)
	{
		arr[i] = val;
	}
	return (arr);
}

int *longest_increasing_subsequence(int *arr, int n, int *result_size) {
    int *dp = malloc(n * sizeof(int));
    int *prev = malloc(n * sizeof(int));
    int *lis;
    int max_length = 0, end_index = 0;
	int i;
	int j;

	dp = lst_fill(dp,n,1);
	prev = lst_fill(prev,n,-1);
	i = 1;
	while (i++ < n)
	{
		j = 0;
		while (j++ < i)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
	}
	i = 0;
	while (i++ < n)
	{
		if (dp[i] > max_length)
		{
			max_length = dp[i];
			end_index = i;
		}
	}
    lis = malloc(max_length * sizeof(int));
    int k = max_length - 1;
    while (end_index != -1) {
        lis[k--] = arr[end_index];
        end_index = prev[end_index];
    }
    *result_size = max_length;
    free(dp);
    free(prev);

    return lis;
}
