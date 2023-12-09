#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string data;
    Node* prev;
    Node* next;

    Node(const string& val) : data(val), prev(nullptr), next(nullptr) {}
};

class List {
private:
    int listSize;
    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr), listSize(0){}

    void add(const string& element) {
        Node* newNode = new Node(element);
        if (!head) {
            head = newNode;
            tail = newNode;
            
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        listSize++;
    }

    void remove() {
        if (tail) {
            if (tail->prev) {
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
            }
            else {
                delete tail;
                head = nullptr;
                tail = nullptr;
            }
        }
        else {
            cout << "Lista jest pusta. Nie można usunąć elementu." << endl;
        }
    }

    bool is_empty() {
        return !head;
    }
    void print_list() {
        Node* current = head;
        int counter = 1;
        while (current) {
            cout << "Element " << counter << ": " << current->data << " "<<endl;
            current = current->next;
            counter++;
        }
        cout << endl;
    }

    int size() {
        int count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }


    void polacz(List& otherList) {
        if (otherList.is_empty()) {
        
            return;
        }

        Node* thisCurrent = this->head;
        Node* otherCurrent = otherList.head;

        while (thisCurrent != nullptr && otherCurrent != nullptr) {
            Node* thisNext = thisCurrent->next;
            Node* otherNext = otherCurrent->next;

            thisCurrent->next = otherCurrent;
            otherCurrent->prev = thisCurrent;

            if (thisNext != nullptr) {
                otherCurrent->next = thisNext;
                thisNext->prev = otherCurrent;
            }
            else {
                this->tail = otherCurrent;
            }

            thisCurrent = thisNext;
            otherCurrent = otherNext;
        }

        this->listSize += otherList.listSize;

    
        otherList.head = nullptr;
        otherList.tail = nullptr;
        otherList.listSize = 0;
    }



 };

int main() {
    List el_listaPrzeciwnikow;
    List el_listaBohaterow;
    int a, b;
    cout << "ilu bohaterow" << endl;
    cin >> a;
    cout << "ilu enemy" << endl;
    cin >> b;
    for (int i = 0; i < a; i++)
    {
        string name = "Finn" + to_string(i + 1);
        
        el_listaBohaterow.add(name);
    }
    for (int i = 0; i < b; i++)
    {
        string name = "The Lich" + to_string(i + 1);
        
        el_listaPrzeciwnikow.add(name);
    }

    el_listaBohaterow.print_list();
    el_listaPrzeciwnikow.print_list();

    el_listaBohaterow.polacz(el_listaPrzeciwnikow);

    el_listaBohaterow.print_list();
    
    return 0;
}
