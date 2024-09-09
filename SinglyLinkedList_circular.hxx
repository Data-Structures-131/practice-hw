#ifndef SINGLY_LINKED_LIST_CIRCULAR_H
#define SINGLY_LINKED_LIST_CIRCULAR_H

#include <iostream>

using namespace std;

class SinglyLinkedListCircular {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* sentinel;

public:
    SinglyLinkedListCircular() {
        sentinel = new Node(0);  
        sentinel->next = sentinel; 
    }

    ~SinglyLinkedListCircular() {
        Node* current = sentinel->next;
        Node* nextNode;
        while (current != sentinel) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete sentinel;  
    }

    void append(int value) {
        Node* newNode = new Node(value);
        Node* last = sentinel;
        while (last->next != sentinel) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = sentinel;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        newNode->next = sentinel->next;
        sentinel->next = newNode;
    }

    void remove(int value) {
        Node* current = sentinel;
        while (current->next != sentinel && current->next->data != value) {
            current = current->next;
        }

        if (current->next != sentinel) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    bool contains(int value) const {
        Node* current = sentinel->next;
        while (current != sentinel) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void print() const {
        Node* current = sentinel->next;
        while (current != sentinel) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif // SINGLY_LINKED_LIST_CIRCULAR_H
