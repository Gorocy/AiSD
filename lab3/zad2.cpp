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

    Student* prev;
    Student* next;

    Student() {
        moc = 0;
        inteligencja = 0;
        determinacja = 0;
        imie = "";
        prev = nullptr;
        next = nullptr;
    }

    Student(int moc, int inteligencja, int determinacja, const string& imie) {
        this->moc = moc;
        this->inteligencja = inteligencja;
        this->determinacja = determinacja;
        this->imie = imie;
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
};

void distributeStudents(List& mainList, List& wimiip, List& wimir, List& wiet) {
    Student* current = mainList.head;
    while (current != nullptr) {
        if (current->moc >= current->inteligencja && current->moc >= current->determinacja) {
            wimiip.addNew();
            wimiip.tail->moc = current->moc;
            wimiip.tail->inteligencja = current->inteligencja;
            wimiip.tail->determinacja = current->determinacja;
            wimiip.tail->imie = current->imie;
        } else if (current->inteligencja >= current->moc && current->inteligencja >= current->determinacja) {
            wimir.addNew();
            wimir.tail->moc = current->moc;
            wimir.tail->inteligencja = current->inteligencja;
            wimir.tail->determinacja = current->determinacja;
            wimir.tail->imie = current->imie;
        } else {
            wiet.addNew();
            wiet.tail->moc = current->moc;
            wiet.tail->inteligencja = current->inteligencja;
            wiet.tail->determinacja = current->determinacja;
            wiet.tail->imie = current->imie;
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

    cout << " Profesorka : Daj mi 4 najlepszych uczniow z najwieksza moca" << endl << endl;

    List dlaProfesorki;
    Student* currentMainList = mainList.head;

    for (int i = 0; i < 4; ++i) {
        Student* maxStudent = currentMainList;
        Student* current = currentMainList->next;

        while (current != nullptr) {
            if (current->moc > maxStudent->moc) {
                maxStudent = current;
            }
            current = current->next;
        }

        dlaProfesorki.addNew();
        dlaProfesorki.tail->moc = maxStudent->moc;
        dlaProfesorki.tail->inteligencja = maxStudent->inteligencja;
        dlaProfesorki.tail->determinacja = maxStudent->determinacja;
        dlaProfesorki.tail->imie = maxStudent->imie;


        mainList.removeStudent(maxStudent->imie);


        currentMainList = mainList.head;
    }
    Student* current = dlaProfesorki.head;
    for(int i =0; i <4; ++i) {

        mainList.addNew();
        mainList.tail->moc = current->moc;
        mainList.tail->inteligencja = current->inteligencja;
        mainList.tail->determinacja = current->determinacja;
        mainList.tail->imie = current->imie;
        current = current->next;
    }


    cout << "Lista 4 najlepszych uczniow z najwieksza moca:" << endl;
    dlaProfesorki.printList();

    return 0;
 }