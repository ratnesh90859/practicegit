#include <iostream>

class node { // You were missing this class definition
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
    node* head;
    node* tail;
    int size; // Added size member variable

public:
    Queue() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0; // Initialize size to 0
    }

    void enqueue(int data) {
        node* newnode = new node(data); // Fixed the new node creation
        if (this->head == nullptr) {
            this->head = this->tail = newnode;
        }
        else {
            this->tail->next = newnode;
            this->tail = newnode;
        }
        this->size++;
    }

    void dequeue() {
        if (this->head == nullptr) {
            return; // The queue is empty
        }
        else {
            node* oldhead = this->head;
            this->head = this->head->next;
            if (this->head == nullptr) this->tail = nullptr;
            delete oldhead;
            this->size--;
        }
    }

    int getsize() {
        return this->size;
    }

    bool isEmpty() { // Fixed the function name
        return this->head == nullptr;
    }

    int front() {
        return this->head->data;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(10);
    q.dequeue();
    q.enqueue(40); // Changed "qu" to "q" for consistency

    while (!q.isEmpty()) { // Changed "qu" to "q" for consistency
        std::cout << q.front() << " ";
        q.dequeue();
    }
    return 0;
}
