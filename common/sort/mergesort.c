#include <stdio.h>

void print_arr(int arr[], int left, int right) {
    int i=left;
    for(;i<=right;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int l, int m, int r) {
    if (l>=r || arr[m] < arr[m+1]) return;
    int j=m+1;
    int i=l;
    int len=r-l+1;
    int tmp[len];
    int pos=0;
    // print_arr(arr, l, r);
    // printf("l:%d , m:%d, r:%d, len:%d\r\n", l, m, r, len);
    while (pos < len && i<=m && j<=r) {
        if (arr[i]<arr[j]) 
            tmp[pos++]=arr[i++];
        else if (arr[j]<=arr[i])
            tmp[pos++]=arr[j++];
    }
    while (i<=m) tmp[pos++]=arr[i++];
    while (j<=r) tmp[pos++]=arr[j++];

    for(pos=0,i=l;i<=r;i++)
        arr[i]=tmp[pos++];
    print_arr(tmp, 0, len-1);
}


void mergesort(int arr[], int left, int right) {
    if (left>=right) return;

    int m = left+(right-left)/2;
    mergesort(arr, left, m);
    mergesort(arr, m+1, right);

    merge(arr, left, m,right);
    return;
}


int main(int argc, char const *argv[]) {
    int arr[16]={28,3,1,23,65,2,43,14,8,67,66,23,45,66,90,20};
    mergesort(arr, 0, 15);
    print_arr(arr, 0, 15);
    return 0;
}
