/* 
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a FIFO stack using a linked list
*/
#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
#include "main.h"

using std::string;
using std::cout;
using std::endl;

struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

class Fifo {

public:
    Fifo();
    bool push(int, string*);
    bool pull(Data*);
    bool peek(Data*);
    bool isEmpty();
    ~Fifo();

private:
    int getCount();
    bool clearList();
    Node *head; 
    bool addTail(int, string*, Node*, bool);
    Node* createNode(int, string*);
};

#endif //LINKED_LIST
