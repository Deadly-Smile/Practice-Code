#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class List {
public:
    Node* head;
    Node* tail;
private:
    int size;
public:
    List () {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

public:
    void add(int data) {
        Node *temp = new Node();
        temp->data = data;
        temp->next = nullptr;
        if(size == 0) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
        temp = nullptr;
        delete temp;
    }

    void displayElement() {
        Node* pointer = head;
        std::cout << size << std::endl;
        while(pointer) {
            std::cout << pointer->data << " ";
            pointer = pointer->next;
        }   std::cout << std::endl;

        pointer = nullptr;
        delete pointer;
    }

    ~List () {
        if(size == 0) {
            delete head;
            delete tail;
        } else {
            Node* pointer = head;
            while(pointer) {
                Node* temp = pointer;
                pointer = pointer->next;
                temp->next = nullptr;
                temp = nullptr;
                delete temp;
            }

            head = nullptr;
            delete head;
            tail = nullptr;
            delete tail;
            pointer = nullptr;
            delete pointer;
        }
    }
};

int main() {
    List arr;
    arr.add(1);
    arr.add(2);
    arr.add(3);
    arr.add(4);
    arr.add(5);
    arr.displayElement();
    return 0;
}