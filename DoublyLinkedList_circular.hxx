#ifndef DOUBLYLINKEDLIST_CIRCULAR_HXX
#define DOUBLYLINKEDLIST_CIRCULAR_HXX

#include <iostream>

using namespace std;

class DoublyLinkedListCircular {
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int val) : data(val), next(this), prev(this) {} 
    };

    Node* head;

public:
    DoublyLinkedListCircular() : head(nullptr) {}

    ~DoublyLinkedListCircular() {
        while (head) {
            pop_front();
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void pop_front() {
        if (!head) return;

        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* tail = head->prev;
            Node* temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
    }

    void print() const {
        if (!head) return;
        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
};

#endif // DOUBLYLINKEDLIST_CIRCULAR_HXX
