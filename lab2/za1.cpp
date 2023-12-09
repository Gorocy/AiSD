#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() : data(0), next(nullptr), prev(nullptr) {

    }

    Node(int data) : data(data), next(nullptr), prev(nullptr) {

    }
};

class List {
public:
    int capacity;
    Node* elements;
    int size;
    Node* currentElement;

    List(int initialCapacity) {
        capacity = initialCapacity;
        size = 0;
        elements = new Node[initialCapacity];
        for (int i = 0; i < capacity; i++) {
            elements[i] = Node();
        }
        currentElement = nullptr;
    }

    ~List() {
        delete[] elements;
    }

    void add(int element) {
        if (size < capacity) {
            elements[size].data = element;
            if (size > 0) {
                elements[size].prev = &elements[size - 1];
                elements[size - 1].next = &elements[size];
            }
            size++;
        }
        else {
            cout << "List is full. Cannot add more elements." << endl;
        }
        if (size == 1) {
            currentElement = &elements[1];
        }
    }

    void remove(Node* element) {
        Node* current = &elements[0];

        while (current != nullptr) {
            if (current == element) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                if (current == currentElement) {
                    currentElement = current->next;
                }

                size--;

                return;
            }
            current = current->next;
        }

        cout << "Element not found. Cannot remove." << endl;
    }

    bool is_empty() {
        return size == 0;
    }

    int get_size() {
        return size;
    }

    void print_list() {
        Node* current = &elements[0];
        int counter = 1;
        while (current != nullptr) {
            cout << "Element " << counter << ": " << current->data << " " << endl;
            current = current->next;
            counter++;
        }
        cout << endl;
    }

    Node* search(int element) {
        Node* current = &elements[0];
        while (current != nullptr) {
            if (current->data == element) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void move_to_next() {
        if (currentElement != nullptr && currentElement->next != nullptr) {
            currentElement = currentElement->next;
        }
    }

    void move_to_previous() {
        if (currentElement != nullptr && currentElement->prev != nullptr) {
            currentElement = currentElement->prev;
        }
    }

    Node* get_current() {
        return currentElement;
    }
};

int main() {
    int a;
    cout << "ile elementow ma miec lista: ";
    cin >> a;
    List myList(a);

    Node* chosen_element = nullptr;
    if (a > 0) {
        chosen_element = myList.currentElement;
    }

    while (true) {
        char choice;
        cout << "Choose an operation (a for add, r for remove, p for print, f for find, n for next, b for back): ";
        if (chosen_element != nullptr) { 
            cout <<endl<< "Current element: "+chosen_element->data << endl;
        }
        cin >> choice;
        
        if (choice == 'a') {
            int element;
            cout << "Enter an element to add: ";
            cin >> element;
            myList.add(element);
        }
        else if (choice == 'r') {
            if (chosen_element != nullptr) {
                myList.remove(chosen_element);
            }
            else {
                cout << "No element selected to remove." << endl;
            }
        }
        else if (choice == 'p') {
            myList.print_list();
        }
        else if (choice == 'f') {
            int element_to_find;
            cout << "Znajdz: ";
            cin >> element_to_find;

            Node* found_node = myList.search(element_to_find);
            if (found_node != nullptr) {
                chosen_element = found_node;
                cout << "Element found: " << found_node->data << endl;
                cout << "Czy chcesz usunąć ten element? (t/n): ";
                char delete_choice;
                cin >> delete_choice;

                if (delete_choice == 't') {
                    myList.remove(found_node);
                    chosen_element = nullptr;
                    cout << "Element usunięty." << endl;
                }
            }
            else {
                cout << "Element not found." << endl;
            }
        }else if (choice == 'b') {
            myList.move_to_next();
            chosen_element = myList.get_current();
        }
        else if (choice == 'n') {
            myList.move_to_next();
            chosen_element= myList.get_current();
        }
        else {
            cout << "Invalid choice. Please enter 'a' for add, 'r' for remove, 'p' for print, or 'f' for find, 'n' for next, 'b' for back" << endl;
        }

        cout << "List size: " << myList.get_size() << endl;
    }

    return 0;
}