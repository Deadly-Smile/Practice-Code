#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r) {
    int count{0};
    int pivot = arr[l];
    for (int i = l+1; i <= r; i++) {
        if(pivot >= arr[i])
            count++;
    }
    int res = l+count;
    std::swap(arr[res], arr[l]);

    int i = l, j = r;
    while(i < res && j > res) {
        while(arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i < res && j > res) {
            std::swap(arr[i++], arr[j--]);
        }
    }
    return res;
}


void quickSort(int arr[], int l, int r) {
    if(l >= r) return;
    int p = partition(arr, l, r);
    quickSort(arr, l, p-1);
    quickSort(arr, p+1, r);
}

int main() {
    int arr[] = {5,4,1,2,1};
    quickSort(arr, 0, 4);
    for (auto &i : arr) {
        std::cout << i << " ";
    }   std::cout << std::endl;
    return 0;
}