#include <iostream>
#include <string>
using namespace std;


class QueueArray {
private:
    struct MyQueue {
        string nazwaPotwora;
        int importance;
    };

    MyQueue queue[10];
    int front;
    int rear;
    int size;

public:
    QueueArray() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(string nazwaPotwora, int importance) {
        if (size < 10) {
            rear = (rear + 1) % 10;
            queue[rear].nazwaPotwora = nazwaPotwora;
            queue[rear].importance = importance;
            size++;

            sortQueueByImportance();
        }
        else {
            cout << "Kolejka potworów jest pełna. Nie można dodać więcej potworów." << endl;
        }
    }

    void enqueue(string nazwaPotwora) {
        if (size < 10) {
            rear = (rear + 1) % 10;
            queue[rear].nazwaPotwora = nazwaPotwora;
           // queue[rear].importance = importance;
            size++;

            sortQueueByImportance();
        }
        else {
            cout << "Kolejka potworów jest pełna. Nie można dodać więcej potworów." << endl;
        }
    }

    string dequeue() {
        if (!is_empty()) {
            string front_element = queue[front].nazwaPotwora;
            front = (front + 1) % 10;
            size--;
            return front_element;
        }
        else {
            cout << "Kolejka potworów jest pusta. Nie można zdjąć elementu." << endl;
            return "ERROR";
        }
    }

    bool is_empty() {
        return size == 0;
    }

    int get_size() {
        return size;
    }

    void displayQueue() {
        for (int i = 0; i < size; i++) {
            cout << "Nazwa: " << queue[i].nazwaPotwora << ", Importance: " << queue[i].importance << endl;
        }
    }

    void sortQueueByImportance() {
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (queue[i].importance < queue[j].importance) {
                    swap(queue[i], queue[j]);
                }
            }
        }
        front = 0;
        rear = size - 1;
    }
};

int main() {
    QueueArray potwory;
    QueueArray zabitePotwory;

    srand(time(NULL));

    string nazwa;
    int importance;
    string nazwaZadan[11];

    nazwaZadan[0] = "Miecz Berengara";
    nazwaZadan[1] = "Pokój Ciri";
    nazwaZadan[2] = "Mysia wieża";
    nazwaZadan[3] = "Zlecenie: Najgroźniejszy potwór na Skellige";
    nazwaZadan[4] = "Zlecenie: Bestia z Hindarsfjall";
    nazwaZadan[5] = "Gwint: Rozgrywki na Skellige";
    nazwaZadan[6] = "Zlecenie: Opiekun lasu";
    nazwaZadan[7] = "Czarna perła";
    nazwaZadan[8] = "Represje w Novigradzie I";
    nazwaZadan[9] = "Serce nie sługa (wybierz jedna, nie popełniaj moich błędów)";
    nazwaZadan[10] = "Gwint: Rozgrywki w Velen";

    for (int i = 0; i <= 8; i++) {
        importance = rand() % 10 + 1;

        nazwa = nazwaZadan[rand() % 11];
        potwory.enqueue(nazwa, importance);
    }
    potwory.displayQueue();

    while (true) {
        cout << "Podaj nazwę potwora/zdarzenie: ";
        cin >> nazwa;
        cout << "Podaj importance: ";
        cin >> importance;

        potwory.enqueue(nazwa, importance);
        potwory.displayQueue();

        if (potwory.get_size() == 10) {
            string zabityPotwor = potwory.dequeue();
            cout << "Geralt WYKONUJE MISJE: " << zabityPotwor << endl;
            zabitePotwory.enqueue(zabityPotwor);
               // string zabityPotwor = potwory.dequeue();
      
           
        }


        if (zabitePotwory.get_size() == 10) {
            cout << "Geralt oddaje 10 misji:" << endl;
            while (!zabitePotwory.is_empty()) {
                string zabityPotwor = zabitePotwory.dequeue();
                cout << zabityPotwor << endl;
            }
        }
    }

    return 0;
}