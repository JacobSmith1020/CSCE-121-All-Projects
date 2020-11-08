#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

// default constructor
LinkedList::LinkedList():
	head(nullptr), tail(nullptr), current(head)
	{}


// destructor
LinkedList::~LinkedList() {
	clear();
}

// copy constructor
LinkedList::LinkedList(const LinkedList& source) {
	copy = new Node;
	*copy = *source.copy;
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
}

// insert operation
void LinkedList::insert(string location, int year, int month, double temperature) {
	current = head;
	Node* newNode = new Node(location, year, month, temperature);
	// TemperatureData NodeValue(location, year, month, temperature);
	if((head == nullptr) && (tail == nullptr)) {
		head = newNode;
		tail = newNode;
		head->next = tail;
		tail->next = nullptr;
	}
	else if((head == tail)) {
		if(newNode < head) {
			previousHead = head;
			head = newNode;
			head->next = previousHead;
			previousHead->next = tail;
		}
		else {
			previousTail = tail;
			tail = newNode;
			head->next = previousTail;
			previousTail->next = newNode;
		}
	}
	else {
		if(newNode < head) {
			previousHead = head;
			head = newNode;
			head->next = previousHead;
		}
		else {
			while(current != tail) {
				if(newNode < current) {
					break;
				}
				current = current->next;
			}
		}
	}
}

void LinkedList::clear() {
	// Implement this function

}

Node* LinkedList::getHead() const {
	return head;
}

string LinkedList::print() const {
	string outputString = "";
	// Implement this function
	Node* current = head;
	while(current != tail) {
		TemperatureData TempData = current->data;
		string location = TempData.getid();
		char year = TempData.getYear();
		char month = TempData.getMonth();
		char temperature = TempData.getTemp();
		string curLine = location + " " + year + " " + month + " " + temperature;
		outputString += curLine;
		current = current->next;
	}
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
