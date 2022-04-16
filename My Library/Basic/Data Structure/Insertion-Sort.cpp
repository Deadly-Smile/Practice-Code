#include<bits/stdc++.h>
using namespace std;

void insertSort(int arr[], int start, int end) {
    for (int i = start+1; i <= end; i++) {
        int temp = arr[i];
        int pointer = i;
        for(int j = i-1; j >= start; j--) {
            pointer = j;
            if(temp < arr[j]) {
                arr[j+1] = arr[j];
            } else {
                pointer++;
                break;
            }
        }
        arr[pointer] = temp;
    }
}

int main () {
    int arr[] = {5,4,3,2,1};
    insertSort(arr, 0, 4);
    for (auto &i : arr) {
        std::cout << i << " ";
    }   std::cout << std::endl;

    return 0;
}