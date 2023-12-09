#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <map>

using namespace std;


class Stos {
private:
    int sizeMax;
    int size;
    char* element;
public:


    void StosSetSize(char a) {
        size = 0;
        sizeMax = a - 1;
        element = new char[a - 1];
    }
    Stos(int a) {
        size = 0;

        element = new char[a];
    }

    ~Stos() {
        delete[] element;
    }

    void print() {
        for (int i = 0; i < sizeMax; i++) {
            cout << element[i] << endl;
        }
    }

    void push(char& elementt) {
        if (size >= sizeMax) {
            cout << "przepelnione" << endl;
        }
        else {
            element[size] = elementt;
            size++;
        }
    }

    char pop() {
        if (size != 0) {
            size--;
            return element[size];
        }
        else {
            return -1;
        }
    }

    bool is_empty() {
        return size == 0;
    }

    int sizeOf() {
        return size;
    }
};

class QueueArray {
public:
    struct MyQueue {
        char name;
        double x;
        double y;
    };

    Stos** elementToFar;
    MyQueue* queue;
    int front;
    int rear;
    int size;
    int maxSize;
   
    QueueArray(int a) {
        elementToFar = new Stos * [a];
        for (int i = 0; i < a; i++) {
            elementToFar[i] = new Stos(a);
        }
        maxSize = a;
        queue = new MyQueue[a];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~QueueArray() {
        delete[] queue;
        for (int i = 0; i < maxSize; i++) {
            delete elementToFar[i];
        }
        delete[] elementToFar;
    }

    void enqueue(double x,double y, char name) {
        if (size < maxSize) {
            rear = (rear + 1) % maxSize;
            queue[rear].x = x;
            queue[rear].y = y;
            queue[rear].name = name;
            size++;

            
            if (size == 9) {
                
            }
        }
        else {
            cout << "Kolejka potworów jest pełna. Nie można dodać więcej potworów." << endl;
        }
    }

    void dequeue() {
        if (!is_empty()) {
    
            front = (front + 1) % maxSize;
            size--;
     
        }
        else {
            cout << "Kolejka potworów jest pusta. Nie można zdjąć elementu." << endl;

        }
    }

    bool is_empty() {
        return size == 0;
    }

    int get_size() {
        return size;
    }
    
    void toFar() {
        
    }

};



int main() {
    int a;
    cout << "ile ma byc punktow na mapie" << endl;
    cin >> a;
    double maxR = 0.0;
    cout << "jaki ma byc promien(wartosc punktu x i y wynosci od -100 do 100)"<<endl;
    cin >> maxR;

    QueueArray points(a);
   

    double x;
    double y;
    char name;

    double xi;
    double yi;
    char char_i;

    double xj;
    double yj;
    char char_j;

    QueueArray::MyQueue element_i;
    QueueArray::MyQueue element_j;

    
    

    for (int i = 0; i < a; i++) {
        
        x = ((rand() % 201) - 100);
        y = ((rand() % 201) - 100);
        name = static_cast<char>(65+i); 
        points.enqueue(x, y, name);
        cout << "name: " << name << ", x: "<<x<<", y:"<< y<< endl;
        points.elementToFar[i]->StosSetSize(a);
    }
    for (int i = 0; i < a-1; i++){
        element_i = points.queue[i];
        xi = element_i.x;
        yi = element_i.y;
        char_i = element_i.name;
        for (int j = i+1; j < a; j++){
            element_j = points.queue[j];
            xj = element_j.x;
            yj = element_j.y;
            char_j = element_j.name;
            if(sqrt((xi - xj)*(xi - xj) + (yi - yj)*(yi - yj)) >= maxR) {
             
             cout << char_i << " + "<< char_j << endl;
             points.elementToFar[i]->push(char_j);
             points.elementToFar[j]->push(char_i);

            }

            
        }
    }
    for (int i = 0; i < a; i++) {
        element_i = points.queue[i];
        char_i = element_i.name;
        cout << "Zawartosc stosu " << char_i  << ":" << endl;
        while (!points.elementToFar[i]->is_empty()) {
            char element = points.elementToFar[i]->pop();
            cout << element << endl;
        }
    }

  
    return 0;
}
