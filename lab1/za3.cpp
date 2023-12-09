#include <iostream>

using namespace std;

class Stack {
public:
    Stack() : capacity(0), size(0) {
        cin >> capacity;
        data = new int[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void push(const int item) {
        if (size == capacity) {
            capacity++;
            int* new_data = new int[capacity];
            for (int i = 0; i < size; i++) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        data[size++] = item;
    }

    int pop() {
        if (!isEmpty()) {
            size--;
            return data[size++];
        }
        else {
            runtime_error("Stack is empty");
        }

    }

    int top() {
        if (!isEmpty()) {
            return data[size - 1];
        }
        throw runtime_error("Stack is empty");
    }

private:
    int* data;
    int capacity;
    int size;
};

class Queue {
public:
    Queue() : capacity(0), size(0), frontIndex(0) {
        cin >> capacity;
        data = new int[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void enqueue(const int item) {
        if (size == capacity) {
            capacity ++;
            int* new_data = new int[capacity];
            for (int i = 0; i < size; i++) {
                new_data[i] = data[(frontIndex + i) % capacity];
            }
            delete[] data;
            data = new_data;
            frontIndex = 0;
        }
        int rearIndex = (frontIndex + size) % capacity;
        data[rearIndex] = item;
        size++;
    }

    void dequeue() {
        if (!isEmpty()) {
            frontIndex = (frontIndex + 1) % capacity;
            size--;
        }
    }

    int front() {
        if (!isEmpty()) {
            return data[frontIndex];
        }
        throw runtime_error("Queue is empty");
    }

private:
    int* data;
    int capacity;
    int size;
    int frontIndex;
};
