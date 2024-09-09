#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

class Queue {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty, cannot dequeue!" << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    int peek() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty, cannot peek!" << std::endl;
            throw std::runtime_error("Queue is empty");
        }
        return front->data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void print() const {
        Node* temp = front;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

#endif // QUEUE_H
