//
// Created by phyxolog on 03.08.18.
//

#include <iostream>

using namespace std;

template <typename T>
class Node {
private:
    T value;

public:
    Node<T> *next;

    T getValue() {
        return value;
    }

    Node(const T &value, Node *next = nullptr)
            : value(value), next(next) {}
};

template <typename T>
class Queue {
private:
    Node<T> *first = nullptr;
    Node<T> *last = nullptr;
    unsigned int size = 0;

public:
    void enqueue(const T &value) {
        Node<T> *n = new Node<T>(value);

        if (first != nullptr) {
            last->next = n;
            last = last->next;
        }
        else {
            first = last = n;
        }

        size++;
    }

    T dequeue() {
        if (first != nullptr) {
            T temp = first->getValue();

            Node<T> *n = first->next;
            delete first;
            first = n;

            size--;

            return temp;
        }

        return T();
    }

    ~Queue() {
        while (first != nullptr) {
            dequeue();
        }
    }

    unsigned int getSize() {
        return size;
    }
};

int main(int argc, char *argv[]) {
    Queue<int> *queue = new Queue<int>;

    queue->enqueue(5);
    queue->enqueue(6);
    queue->enqueue(10);
    queue->enqueue(8);

    cout << "Size: " << queue->getSize() << endl;     // 2

    cout << queue->dequeue() << endl;                 // 5
    cout << queue->dequeue() << endl;                 // 6
    cout << queue->dequeue() << endl;                 // 10
    cout << queue->dequeue() << endl;                 // 8
    cout << queue->dequeue() << endl;                 // 0 because now queue was empty

    return 0;
}