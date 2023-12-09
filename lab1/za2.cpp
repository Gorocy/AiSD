#include <iostream>
using namespace std;



class Stos {
private:
	int size;
	int element[10];

public:
	

	void push(int elementADD) {
		if (size>9) {
			cout << "przepelnione" << endl;
			
		}
		else {
			element[size] = elementADD;
			size++;
		}
	}
	int pop() {
		if (size != 0) {
			return element[size--];
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