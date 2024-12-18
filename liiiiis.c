#include <stdlib.h>

void initialize_arrays(int *dp, int *prev, int n) {
    for (int i = 0; i < n; i++) {
		dp[i] = 1;                prev[i] = -1;         
	}
}

void calculate_lis(int *arr, int n, int *dp, int *prev, int *max_length, int *end_index) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    *max_length = 0;
    *end_index = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > *max_length) {
            *max_length = dp[i];
            *end_index = i;
        }
    }
}

int *construct_lis(int *arr, int *prev, int end_index, int max_length) {
    int *lis = malloc(max_length * sizeof(int));
    int k = max_length - 1;
    while (end_index != -1) {
        lis[k--] = arr[end_index];
        end_index = prev[end_index];
    }
    return lis;
}

int *longest_increasing_subsequence(int *arr, int n, int *result_size) {
    int *dp = malloc(n * sizeof(int));
    int *prev = malloc(n * sizeof(int));
    int max_length, end_index;

        initialize_arrays(dp, prev, n);

        calculate_lis(arr, n, dp, prev, &max_length, &end_index);

        int *lis = construct_lis(arr, prev, end_index, max_length);
    *result_size = max_length;

    free(dp);
    free(prev);
    return lis;
}
