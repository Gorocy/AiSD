#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};




class ListNode {
public:
    Node* head;

    ListNode() {
        head = nullptr;
    }

    int countMultiplesOfFirstElement(Node* head) {
        if (head == nullptr) {
            return 0;
        }

        int firstElementValue = head->data;
        int count = 0;
        Node* current = head->next;

        while (current != nullptr) {
            if (current->data % firstElementValue == 0) {
                count++;
            }
            current = current->next;
        }

        return count;
    }



void addElementsToList(Node*& head, int count) {
    if (count <= 0) {
        return;
    }

    if (head == nullptr) {
        cout << "Podaj wartosc pierwszego elementu: ";
        int firstValue;
        cin >> firstValue;
        head = new Node(firstValue);
    }

    Node* current = head;

    for (int i = 0; i < count; i++) {
        int value;
        cout << "Podaj wartosc elementu " << i + 2 << ": ";
        cin >> value;
        Node* newNode = new Node(value);
        current->next = newNode;
        current = newNode;
    }
}
};

int main() {

    ListNode ls;
    int elementCount;

    cout << "Podaj ilosc elementow do dodania: ";
    cin >> elementCount;

    ls.addElementsToList(ls.head, elementCount);

    int result = ls.countMultiplesOfFirstElement(ls.head);
    cout << "Liczba elementow bedacych wielokrotnosciami pierwszego elementu: " << result << endl;

    while (ls.head != nullptr) {
        Node* temp = ls.head;
        ls.head = ls.head->next;
        delete temp;
    }

    return 0;
}
