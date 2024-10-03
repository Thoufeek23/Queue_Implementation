#include "queue.h"
#include <iostream>

using namespace std;

int main() {
    int max_size;
    cout << "Enter the maximum size of the queue: ";
    cin >> max_size;

    Queue queue(max_size);

    string command;
    while (true) {
        cout << "\nEnter a command (enqueue, dequeue, peek, size, display, expand, exit): ";
        cin >> command;

        if (command == "enqueue") {
            if (queue.isFull()) {
                cout << "Queue is full! Cannot enqueue more elements." << endl;
            } else {
                int data;
                cout << "Enter the data to enqueue: ";
                cin >> data;
                queue.enqueue(data);
            }
        } else if (command == "dequeue") {
            queue.dequeue();
        } else if (command == "peek") {
            queue.peek();
        } else if (command == "size") {
            queue.size();
        } else if (command == "display") {
            queue.display();
        } else if (command == "expand") {
            int new_size;
            cout << "Enter the new maximum size for the queue: ";
            cin >> new_size;
            queue.expand(new_size);
        } else if (command == "exit") {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid command! Please try again." << endl;
        }
    }

    return 0;
}
