#include<bits/stdc++.h>
using namespace std;

class stackUp {
private:
    const int N = 1e5 + 1;
    int* arr;
    int size;
    int pointer;

public:
    stackUp () {
        arr = new int[N]();
        size = 0;
        pointer = -1;
    }

    void add (int data) {
        pointer++;
        arr[pointer] = data;
        size++;
    }
    
    int top () {
        if(size)
            return arr[pointer];
        return INT_MIN;
    }

    void pop () {
        if(size) {
            arr[pointer] = 0;
            pointer--;
            size--;
        } else {
            std::cout << "Already empty !!" << std::endl;
        }        
    }

    void displayElement() const {
        std::cout << size << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }   std::cout << std::endl;
    }

    ~stackUp () {
        arr = nullptr;
        delete arr;
        size = 0;
        pointer = -1;
    }
};

int main () {
    stackUp stk;
    stk.add(1);
    stk.add(2);
    stk.add(3);
    stk.add(4);
    stk.add(5);
    stk.add(6);
    stk.displayElement();
    std::cout << stk.top() << std::endl;
    stk.pop();
    stk.pop();
    stk.pop();
    std::cout << stk.top() << std::endl;
    stk.displayElement();

    return 0;
}