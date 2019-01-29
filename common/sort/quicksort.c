#include <stdio.h>

void print_arr(int arr[], int left, int right) {
    int i = left;
    for (; i <= right; i++) printf("%d ", arr[i]);
    printf("\n");
}

void swap(int arr[], int x, int y) {
    if (x == y) return;
    arr[x] = arr[x] + arr[y];
    arr[y] = arr[x] - arr[y];
    arr[x] = arr[x] - arr[y];
}

int partition(int arr[], int left, int right, int pivot) {
    int idx = left;
    int i = idx, j = right;
    while (i < j) {
        while (arr[j] >= pivot && i < j) j--;
        if (i != j) {
            swap(arr, idx, j);
            idx = j;
        }
        while (arr[i] <= pivot && i < j) i++;
        swap(arr, idx, i);
        idx = i;
        print_arr(arr, left, right);
    }
    return idx;
}

void quicksort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[left];
    int idx = partition(arr, left, right, pivot);
    quicksort(arr, left, idx - 1);
    quicksort(arr, idx + 1, right);
    return;
}

int main(int argc, char const *argv[]) {
    int arr[16] = {28, 3, 1, 23, 65, 2, 43, 14, 8, 67, 66, 23, 45, 66, 90, 20};
    quicksort(arr, 0, 15);
    print_arr(arr, 0, 15);
    return 0;
}
