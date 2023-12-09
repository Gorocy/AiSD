#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Student {
public:
    int moc;
    int inteligencja;
    int determinacja;
    string imie;
    string wydzial;

    int points;

    Student* prev;
    Student* next;

    Student() {
        moc = 0;
        inteligencja = 0;
        determinacja = 0;
        imie = "";
        wydzial ="";
        points = 0;

        prev = nullptr;
        next = nullptr;
    }

    Student(int moc, int inteligencja, int determinacja, const string& imie) {
        this->moc = moc;
        this->inteligencja = inteligencja;
        this->determinacja = determinacja;
        this->imie = imie;
        wydzial ="";
        points = 0;

        prev = nullptr;
        next = nullptr;
    }
};

class List {
public:
    int size;
    Student* head;
    Student* tail;

    List() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void addNew() {
        int moc = rand() % 10 + 1;
        int determinacja = rand() % 10 + 1;
        int inteligencja = rand() % 10 + 1;

        string imie = "Student" + to_string(size + 1);

        auto* newStudent = new Student(moc, inteligencja, determinacja, imie);

        if (head == nullptr) {
            newStudent->prev = nullptr;
            head = newStudent;
            tail = newStudent;
        } else {
            newStudent->prev = tail;
            tail->next = newStudent;
            tail = newStudent;
        }

        size++;
    }

    void removeStudent(const string& name) {
        Student* current = head;
        while (current != nullptr) {
            if (current->imie == name) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                delete current;
                size--;
                break;
            }
            current = current->next;
        }
    }

    void printList() {
        Student* current = head;
        while (current != nullptr) {
            cout << "Imie: " << current->imie << ", Moc: " << current->moc
                 << ", Determinacja: " << current->determinacja << ", Inteligencja: " << current->inteligencja << endl;
            current = current->next;
        }
        cout << endl;
    }
    void printListWithWydzial() {
        Student* current = head;
        while (current != nullptr) {
            cout << "Imie: " << current->imie << ", Moc: " << current->moc
                 << ", Determinacja: " << current->determinacja << ", Inteligencja: " << current->inteligencja<<", Wydzial: "<< current->wydzial <<", Punkty: "<< current->points<< endl;
            current = current->next;
        }
        cout << endl;
    }

    void sortByRanking() {
        for(Student* i = head; i != nullptr; i = i->next) {
            for(Student* j = i->next; j != nullptr; j = j->next) {
                if (i->points < j->points) {
                    // Swap the data of i and j
                    swap(i->points, j->points);
                    swap(i->moc, j->moc);
                    swap(i->inteligencja, j->inteligencja);
                    swap(i->determinacja, j->determinacja);
                    swap(i->imie, j->imie);
                    swap(i->wydzial, j->wydzial);
                }
            }
        }
    }
};

void distributeStudents(List& mainList, List& wimiip, List& wimir, List& wiet) {
    Student* current = mainList.head;
    while (current != nullptr) {
        if (current->moc >= current->inteligencja && current->moc >= current->determinacja) {
            wimiip.addNew();
            wimiip.tail->moc = current->moc;
            wimiip.tail->inteligencja = current->inteligencja;
            wimiip.tail->determinacja = current->determinacja;
            wimiip.tail->imie = current->imie ;
            current->wydzial = "wimip";
            current->points = current->determinacja + current->inteligencja + current->moc;
        } else if (current->inteligencja >= current->moc && current->inteligencja >= current->determinacja) {
            wimir.addNew();
            wimir.tail->moc = current->moc;
            wimir.tail->inteligencja = current->inteligencja;
            wimir.tail->determinacja = current->determinacja;
            wimir.tail->imie = current->imie;
            current->wydzial = "wimir";
            current->points = current->determinacja + current->inteligencja + current->moc;
        } else {
            wiet.addNew();
            wiet.tail->moc = current->moc;
            wiet.tail->inteligencja = current->inteligencja;
            wiet.tail->determinacja = current->determinacja;
            wiet.tail->imie = current->imie;
            current->wydzial = "wiet";
            current->points = current->determinacja + current->inteligencja + current->moc;
        }
        current = current->next;
    }

}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    List mainList;
    List wimiip;
    List wimir;
    List wiet;

    for (int i = 0; i < 30; i++) {
        mainList.addNew();
    }


    distributeStudents(mainList, wimiip, wimir, wiet);

    cout << "Lista studentów przed sortowaniem według preferencji:" << endl;
    mainList.printList();

    cout << "Lista dla Wydziału Iluzji, Manipulacji i Inżynierii Potężnej:" << endl;
    wimiip.printList();

    cout << "Lista dla Wydziału Inkantacji Magicznej i Rekreacyjnej:" << endl;
    wimir.printList();

    cout << "Lista dla Wydziału Inżynierii Ezoterycznej i Telepatii:" << endl;
    wiet.printList();

    cout << "Lista studentów przed sortowaniem według preferencji:" << endl;
    mainList.printListWithWydzial();

    cout<< "Lista dla dziekana po posortowaniu"<< endl;
    mainList.sortByRanking();
    mainList.printListWithWydzial();

    return 0;
}
