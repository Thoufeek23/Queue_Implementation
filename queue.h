#ifndef QUEUE_H
#define QUEUE_H

class Node {
public:
    int data;
    Node* next;
    Node(int data);
};

class Queue {
private:
    Node* front;
    Node* rear;
    int count;
    int max_size;

public:
    Queue(int max_size);
    bool isEmpty();
    bool isFull();
    void enqueue(int data);
    void dequeue();
    void peek();
    void size();
    void display();
    void expand(int new_size);
};

#endif
