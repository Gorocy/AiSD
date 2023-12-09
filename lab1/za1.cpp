#include <iostream>
using namespace std;
void main() {
  



}




class QueueArray {
private:
    int queue[10];
    int front;
    int rear;
    int size;

public:
    QueueArray() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int element) {
        if (size < 10) {
            rear = (rear + 1) % 10;
            queue[rear] = element;
            size++;
        }
        else {
            cout << "Queue is full. Cannot enqueue element." << endl;
        }
    }

    int dequeue() {
        if (!is_empty()) {
            int front_element = queue[front];
            front = (front + 1) % 10;
            size--;
            return front_element;
        }
        else {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; 
        }
    }

    bool is_empty() {
        return size == 0;
    }

    int get_size() {
        return size;
    }
};



class QueueDynamic {
private:
    int* queue;
    int front;
    int rear;
    int size;
    int capacity;

public:
    QueueDynamic() {
        capacity = 10;
        queue = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~QueueDynamic() {
        delete[] queue;
    }

    void enqueue(int element) {
        if (size < capacity) {
            rear = (rear + 1) % capacity;
            queue[rear] = element;
            size++;
        }
        else {
            cout << "Queue is full. Cannot enqueue element." << endl;
        }
    }

    int dequeue() {
        if (!is_empty()) {
            int front_element = queue[front];
            front = (front + 1) % capacity;
            size--;
            return front_element;
        }
        else {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; 
        }
    }

    bool is_empty() {
        return size == 0;
    }

    int get_size() {
        return size;
    }
};