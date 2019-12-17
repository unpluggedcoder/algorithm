#include <stdio.h>

void print_arr(int arr[], int left, int right) {
    int i = left;
    for (; i <= right; i++) printf("%d ", arr[i]);
    printf("\n");
}

void swap(int arr[], int x, int y) {
    if (x==y) return;
    arr[x] = arr[x] + arr[y];
    arr[y] = arr[x] - arr[y];
    arr[x] = arr[x] - arr[y];
}

void bubblesort(int arr[], int len) {
    int i, j;
    for(j=len-1; j>=1; j--) {
        for (i=0; i<j; i++ ){
            if(arr[i]>arr[i+1]) swap(arr, i, i+1);
            print_arr(arr, 0, len-1);
        }
        print_arr(arr, 0, len-1);
    }
}

int main(int argc, char const *argv[]) {
    int arr[16] = {28, 3, 1, 23, 65, 2, 43, 14, 8, 67, 66, 23, 45, 66, 90, 20};
    bubblesort(arr, 16);
    print_arr(arr, 0, 15);
    return 0;
}
