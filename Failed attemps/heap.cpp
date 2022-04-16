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
class MaxHeap {
private:
    const int N = 1e5 + 1;
    int size;
    int* arr;
    int pointer;
public:
    MaxHeap() {
        arr = new int[N];
        size = 0;
        pointer = 0;
    }

    void insert (int x) {
        pointer++;
        size++;
        arr[pointer] = x;

        int temp1 = pointer/2;
        int temp2 = pointer;
        while(temp1) {
            if(arr[temp1] < arr[temp2]) {
                std::swap(arr[temp1], arr[temp2]);
            } else break;
            temp2 = temp1;
            temp1 /= 2;
        }
    }

    void deleteTop() {
        if(!size) {
            std::cout << "Can't delete any more element." << std::endl;
            return;
        }
        if(size == 1) {
            pointer--;
            size--;
            return;
        }

        arr[1] = arr[pointer];
        int temp = 1;
        pointer--;
        size--;
        while(temp <= pointer) {
            int x = temp*2;
            if(arr[x] > arr[x+1]) {
                std::swap(arr[temp], arr[x]);
                temp = x;
            } else if (arr[x] < arr[x+1]) {
                std::swap(arr[temp], arr[x+1]);
                temp = x+1;
            } else {
                break;
            }
        }
    }

    void displayElement() {
        std::cout << "Elements : ";
        for (int i = 1; i <= size; i++) {
            std::cout << arr[i] << " ";
        }   std::cout << std::endl;
    }

    ~MaxHeap () {
        arr = nullptr;
        size = 0;
        pointer = 0;
        delete arr;
    }

};

int main() {
    FastIO;

    MaxHeap heap;
    heap.insert(5);
    heap.displayElement();
    heap.insert(1);
    heap.displayElement();
    heap.insert(3);
    heap.displayElement();
    heap.insert(4);
    heap.displayElement();
    heap.insert(2);
    heap.displayElement();
    heap.insert(8);
    heap.displayElement();

    heap.deleteTop();
    heap.displayElement();
    heap.deleteTop();
    heap.displayElement();
    heap.deleteTop();
    heap.displayElement();
    
    return 0;
}