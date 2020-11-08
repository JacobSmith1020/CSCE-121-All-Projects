#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
    class Node {
        public:
        int value;
        Node* next;
        Node(): Node(0) {}
        Node(int value): value(value), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    unsigned int size;

    public:
    LinkedList();
    unsigned int length();
    void appendFront(int value);
    void appendBack(int value);
    void insert(int value, unsigned int index);
    bool hasValue(int value);

};

LinkedList::LinkedList(): head(nullptr), tail(nullptr), size(0) {}

unsigned int LinkedList::length() {
    return size;
}

void LinkedList::appendFront(int value) {
    Node* node = new Node(value);
    if(head) {
        node->next = head;
    }
    else {
        tail = node;
    }
    head = node;
    size++;
}

void LinkedList::appendBack(int value) {
    Node* node = new Node(value);
    if(head) {
        tail->next = head;
    }
    else {
        head = node;
    }
    tail = node;
    size++;
}

void LinkedList::insert(int value, unsigned int index) {
    // TODO
}

bool LinkedList::hasValue(int value) {
    Node* current = head;
    while(current) {
        if(current->value == value) {

        }
    }
}
#endif