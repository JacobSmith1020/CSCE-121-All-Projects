#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include "Node.h"

class LinkedList {
	Node* head;
	Node* tail;
	std::string name;

public:
	LinkedList();
	LinkedList(std::string);
    // FIXME: Add destructor declaration
    ~LinkedList();

	void setName(std::string);
	std::string getName() const;
    
    bool empty() const;

	bool hasValue(int value) const;

    Node* getHead();
    Node* getTail();
    
    void print() const;
    void print(std::ostream& os) const;
    
    void insertFront(int val);
    void insertBack(int val);
    bool insertAfter(int afterVal, int insertVal);

    void clear();  

    void log(std::string) const;
};

std::ostream& operator<<(std::ostream&, const LinkedList&);

#endif