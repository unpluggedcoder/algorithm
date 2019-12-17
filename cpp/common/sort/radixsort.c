#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BASE = 256;

void print_arr(int arr[], int left, int right) {
    int i = left;
    for (; i <= right; i++) printf("%d ", arr[i]);
    printf("\n");
}

void radix_sort(int arr[], int n) {
    int i, j, exp = 1, max = 0;
    for (i = 0; i < n; i++)
        if (arr[i] > max) max = arr[i];
    int *tmp = malloc(sizeof(int) * n);
    int *bucket = malloc(sizeof(int) * BASE);
    while (max / exp > 0) {
        memset(bucket, 0, sizeof(int) * BASE);
        for (i = 0; i < n; i++) bucket[arr[i] / exp % BASE]++;
        for (i = 1; i < BASE; i++) bucket[i] += bucket[i - 1];
        for (i = n - 1; i >= 0; i--)
            tmp[--bucket[arr[i] / exp % BASE]] = arr[i];
        for (i = 0; i < n; i++) arr[i] = tmp[i];
        exp *= BASE;
    }
    free(tmp);
    free(bucket);
    return;
}

int main(int argc, char const *argv[]) {
    int arr[16] = {28, 3, 1, 23, 65, 2, 43, 14, 8, 67, 66, 23, 45, 66, 90, 20};
    radix_sort(arr, 16);
    print_arr(arr, 0, 15);
    return 0;
}
