// intlist.cpp
// Implements class IntList
// Jingyang Liu 4/9/2026


#include "intlist.h"
#include <iostream>
using std::cout;


// copy constructor
IntList::IntList(const IntList& source) {
    head = 0;
    tail = 0;
    Node* curr = source.head;
    while (curr) {
        Node* newNode = new Node;
        newNode->info = curr->info;
        newNode->next = 0;
        if (head == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        curr = curr->next;
    }
}


// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}


// return sum of values in list
int IntList::sum() const {
    Node* curr = head;
    int summ = 0;
    while (curr) {
        summ += curr->info;
        curr = curr->next;
    }
    return summ; // REPLACE THIS NON-SOLUTION
}


// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;
    bool found = false;
    while (curr && !found) {
        if (curr->info == value) {
            found = true;
        }
        curr = curr->next;
    }
    return found; // REPLACE THIS NON-SOLUTION
}


// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* curr = head;
    if (!curr) return 0;
    int max_v = curr->info;
    while (curr) {
        if (curr->info > max_v) {
            max_v = curr->info;
        }
        curr = curr->next;
    }
    return max_v; // REPLACE THIS NON-SOLUTION
}


// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double summ = sum();
    int cnt = count();
    if (cnt == 0) return 0.0;
    double avg = summ / cnt;
    return avg; // REPLACE THIS NON-SOLUTION
}


// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = head;
    if (!tail) tail = newNode;
    head = newNode;
}


// append value at end of list
void IntList::push_back(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = 0;
    if (head == 0) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}


// return count of values
int IntList::count() const {
    int cnt = 0;
    Node* curr = head;
    while (curr) {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) return *this;
    Node* curr = head;
    Node* next = nullptr;
    while (curr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
    head = 0;
    tail = 0;
    curr = source.head;
    while (curr) {
        Node* tmp = new Node;
        tmp->info = curr->info;
        tmp->next = curr->next;
        if (!head) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tmp;
        }
        curr = curr->next;
    }
    return *this;
}


// constructor sets up empty list
IntList::IntList() {
    head = 0;
    tail = 0;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}
