/* 
Name: Michael Brady
Programming Fundamentals III
Purpose: This program creates a FIFO stack using a linked list
*/

#include "fifo.h"

Fifo::Fifo(){
    head = NULL;
}

bool Fifo::push(int id, string* data){
    bool success = false;
    if(id >= 0 && *data != ""){
        if(head == NULL){
            Node *newNode = createNode(id, data);
            head = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
            success = true;
        }else if(getCount() <= STACK_SIZE){
            Node *current = head;
            while(current && success == false && id != current->data.id){
                if(current->next == NULL){
                    success = addTail(id, data, current, success);
                }
                current = current->next;
            }
        }
    }
    return success;
}

bool Fifo::pull(Data* data){
    bool success = false;
    if(head && getCount() > 0){
        data->id = head->data.id;
        data->data = head->data.data;
        Node* current = head;
        if(current->next == NULL){
            head = NULL;
        }else{
            current->next->prev = NULL;
            head = current->next;
        }
        delete head;
        success = true;
    }
    return success;
}

bool Fifo::peek(Data* data){
    bool success = false;
    if(head){
        data->id = head->data.id;
        data->data = head->data.data;
        success = true;
    }
    return success;
}

bool Fifo::isEmpty(){
    return head == NULL;
}

int Fifo::getCount(){
    int count = 0;
    Node *current = head; 
    while(current){
        current = current->next;
        count++;
    }
    return count;
}

bool Fifo::clearList(){
    bool success = false;
    Node *current = head;
    while(current){
        delete head;
        current = current->next;
        head = current;
    }
    if(!current){
        success = true;
    }
    head = NULL;
    return success;
}

Fifo::~Fifo(){
    clearList();
}

bool Fifo::addTail(int id, string* data, Node* current, bool success){
    Node *newNode = createNode(id, data);
    newNode->next = NULL;  
    newNode->prev = current;
    current->next = newNode;
    success = true;
    return success;
}

Node* Fifo::createNode(int id, string* data){
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;
    return newNode;
}
