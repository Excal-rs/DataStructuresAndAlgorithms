#include "LinkedList.h"
#include "Node.h"

// Constructor / Destructor
LinkedList::LinkedList() : size(0), frontNode(nullptr), backNode(nullptr) {}
LinkedList::~LinkedList() {
    for (int i = 0; i<size; i++){
        delete get(i);
    }
}

// Insertion methods
void LinkedList::insert(int data, int index){
    if (index == 0){
        prepend(data);
    } if (index == size - 1){
        append(data);
    }
    
    Node* previous = get(index - 1);
    Node* next = get(index);
    Node newNode(data, previous, next);
    
    previous->setNext(&newNode);
    next->setPrevious(&newNode);
} 

void LinkedList::append(int data){
    Node newNode(data, backNode);
    backNode = &newNode;
}

void LinkedList::prepend(int data){
    Node newNode(data, nullptr, frontNode);
    frontNode = &newNode;
}

