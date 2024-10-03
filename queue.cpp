#include "queue.h"
#include <iostream>

using namespace std;

Node::Node(int data) {
    this->data = data;
    this->next = nullptr;
}

Queue::Queue(int max_size) {
    front = nullptr;
    rear = nullptr;
    count = 0;
    this->max_size = max_size;
}

bool Queue::isEmpty() {
    return front == nullptr;
}

bool Queue::isFull() {
    return count == max_size;
}

void Queue::enqueue(int data) {
    if (isFull()) {
        cout << "Queue is full! Cannot enqueue more elements." << endl;
        return;
    }
    Node* newNode = new Node(data);
    if (rear) {
        rear->next = newNode;
    } else {
        front = newNode;
    }
    rear = newNode;
    count++;
    cout << "Enqueued " << data << " into the queue." << endl;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot dequeue." << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr; 
    }
    cout << "Dequeued " << temp->data << " from the queue." << endl;
    delete temp;
    count--;
}

void Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot peek." << endl;
    } else {
        cout << "Front element is " << front->data << "." << endl;
    }
}

void Queue::size() {
    cout << "Current queue size: " << count << " (Max size: " << max_size << ")" << endl;
}

void Queue::display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        Node* current = front;
        cout << "Queue elements from front to rear: ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "None" << endl;
    }
}

void Queue::expand(int new_size) {
    if (new_size <= max_size) {
        cout << "New size must be greater than current max size." << endl;
        return;
    }
    max_size = new_size;
    cout << "Expanded queue size to " << max_size << "." << endl;
}
