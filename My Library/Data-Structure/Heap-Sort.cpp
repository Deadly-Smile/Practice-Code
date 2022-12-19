//----------------------Created by Anik Saha---------------------------//
#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false);    cin.tie(NULL)
#define Ignore cin.ignore()
typedef unsigned char Byte;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pairs;
typedef std::vector<int> VI;
typedef std::vector<pairs> VII;
//---------------------------Good luck---------------------------------//
template<typename T>
void inputArray(T arr[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void bubbleSort (int arr[], int n) {
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        if(arr[i] < arr[j])
	        	std::swap(arr[i], arr[j]);
	    }
	}
}

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

void selectionSort (int arr[], int start, int end) {
	for (int i = start; i <= end; i++) {
		int m{INT_MAX};
	    for (int j = i; j <= end; j++) {
	        m = std::min(m, arr[j]);
	    }
	    arr[i] = m;
	}
}
void marge (int arr[], int start, int mid, int end) {
	int n1 = mid-start+1;
	int n2 = mid-end;
	int arr1[n1], arr2[n2];
	for (int i = 0; i < n1; i++) {
	    arr1[i] = arr[i+start];
	}
	for (int i = 0; i < n2; i++) {
	    arr2[i] = arr[i+mid+1];
	}
	int p1{0},p2{0};
    while(p1 < n1 && p2 < n2) {
        if(arr1[p1] <= arr2[p2]) 
            arr[start++] = arr1[p1++];
        else 
            arr[start++] = arr2[p2++];
    }
    while(p1 < n1) {
        arr[start++] = arr1[p1++];
    }
    while(p2 < n2) {
        arr[start++] = arr2[p2++];
    }
}
void margeSort (int arr[], int start, int end) {
	if(start >= end)	return;
	int mid = ((end-start) / 2) + start;
	margeSort(arr, start, mid);
	margeSort(arr, mid+1, end);
	marge(arr, start, mid, end);
}

int partition (int arr[], int start, int end) { 
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[end]);
    return ++i;
}
void quickSort (int arr[], int start, int end) {
	if(start >= end)	return;
	int p = partition(arr, start, end);
	quickSort(arr, start, p-1);
	quickSort(arr, p+1, end);
}

void heapSort(int arr[], int n) {
    int heap[n+1] = {0};

    for (int i = 0; i < n; i++) {
        heap[i+1] = arr[i];
        int temp = i+1;
        while(heap[temp] >= heap[temp/2] && temp/2) {
            std::swap(heap[temp], heap[temp/2]);
            temp /= 2;
        }
    }

    for (int i = 0; i < n; i++) {
        int l = 1, r = n-i;
        std::swap(heap[l], heap[r]);
        int c1 = l*2, c2 = l*2 + 1;

        while(c1 < r || c2 < r) {
            if(c1 >= r || c2 >= r) {
                if(c1 >= r) {
                    if(heap[l] < heap[c2]) {
                        std::swap(heap[l], heap[c2]);
                        break;
                    }
                } else {
                	if(heap[l] < heap[c1]) {
	                    std::swap(heap[l], heap[c1]);
	                    break;
	                }
                }
                break;
            }
            if(heap[c1] >= heap[c2]) {
                if(heap[l] < heap[c1]) {
                    std::swap(heap[l], heap[c1]);
                    l = c1;
                } else break;
            } else {
                if(heap[l] < heap[c2]) {
                    std::swap(heap[l], heap[c2]);
                    l = c2;
                } else break;
            }
            c1 = l*2;
        	c2 = l*2 + 1;
        }
    }
    for(int i = 0; i < n; i++) {
        arr[i] = heap[i+1];
    }
}

int main() {
    FastIO;

    int test{0};   std::cin >> test;
    while(test--) {
    	int n{0};   std::cin >> n;
    	int arr[n]; inputArray(arr, n);
    	// bubbleSort
    	bubbleSort(arr, n);
    	for (auto &i : arr) {
    	    std::cout << i << " ";
    	}	std::cout << std::endl;

    	// insertionSort
    	insertSort(arr, 0, n-1);
    	for (auto &i : arr) {
    	    std::cout << i << " ";
    	}	std::cout << std::endl;

    	// selectionSort
    	selectionSort(arr, 0, n-1);
    	for (auto &i : arr) {
    	    std::cout << i << " ";
    	}	std::cout << std::endl;

    	// margeSort
    	margeSort(arr, 0, n-1);
    	for (auto &i : arr) {
    	    std::cout << i << " ";
    	}	std::cout << std::endl;

    	// quickSort
    	quickSort(arr, 0, n-1);
    	for (auto &i : arr) {
    	    std::cout << i << " ";
    	}	std::cout << std::endl;

    	// heapSort
    	heapSort(arr, n);
    	for (auto &i : arr) {
    	    std::cout << i << " ";
    	}	std::cout << std::endl;
    }
    
    return 0;
}