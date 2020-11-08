#include <iostream>
#include "LinkedListLab.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {
    // log("LinkedList() called");
}

LinkedList::LinkedList(string name) : head(nullptr), tail(nullptr), name(name) {
    // log("LinkedList(string) called");
}

// FIXME: 
//   1) add destructor definition
//   2) add log("~LinkedList() called"); at
//       beginning of destructor
LinkedList::~LinkedList() {
    clear();
    // log("~LinkedList() called");
}

void LinkedList::setName(string name) {
	this->name = name;
}

string LinkedList::getName() const {
	return name;
}

bool LinkedList::hasValue(int value) const {
    Node* cur = head;
    while (cur != nullptr) {
        if (cur->value == value) {
            return true;
        }
        cur = cur->next;
    }
	return false; // stub we'll have to fix
}

bool LinkedList::empty() const {
    return head == nullptr;
}

Node* LinkedList::getHead() {
    return head;
}

Node* LinkedList::getTail() {
    return tail;
}

void LinkedList::print() const {
    print(cout);
}

void LinkedList::print(ostream& os) const {
    // output to the file stream
    // separate each item with the character passed in, i.e. c
    os << name << " { ";
    if (head == nullptr) 
        os << "<Empty List>";
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->value;
        if (cur != tail)
            cout << ", ";
        cur = cur->next;
    }
    os << " }";
}

void LinkedList::insertFront(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr)
        tail = newNode; // tail = head;
    
    /* Alternative logic 
    Node* newNode = new Node(val);
    if (head == nulptr) { // empty list
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head; // connect to next node
        head = newNode;
    }
    */    
}

void LinkedList::insertBack(int val) {
    Node* newNode = new Node(val);
    newNode->next = tail;
    if (tail == nullptr) {
        head = newNode;
    }
    tail = newNode;
}

bool LinkedList::insertAfter(int afterVal, int insertVal) {
    Node* cur = head;
    while (cur != nullptr && cur->value != afterVal) {
        cur = cur->next;
    }
    // either did not find (cur is nullptr) or nullptr points to node with value
    if (cur == nullptr) {
        return false;
    }
    // now cur points to a node
    Node* newNode = new Node(insertVal);
    newNode->next = cur->next;
    cur->next = newNode;
    if (cur == tail) { 
        tail = newNode;
    }
}

// This function will output 
void LinkedList::log(string what) const
{
    std::cout << "[" << this << "] " << what << std::endl;
}


// FIXME: add definition for clear
void LinkedList::clear() {
    Node* cur = head;
    Node* newNode = head->next;
    while(cur != nullptr) {
        newNode = head->next;
        delete cur;
        cur = nullptr;
        head = newNode;
        cur = head;
    }
}


std::ostream& operator<<(std::ostream& os, const LinkedList& ll) {
    ll.print(os);
    return os;
}





