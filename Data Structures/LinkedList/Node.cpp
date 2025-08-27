#include "Node.h"

// Constructor
Node::Node(int data, Node* previous, Node* next): data(data), previous(previous), next(next){}


// Getters -------------------------------
Node* Node::getNext(){
    return next;
}
    
Node* Node::getPrevious(){
    return previous;
}

int Node::getData(){
    return data;
}

// Setters -------------------------------
void Node::setNext(Node* newNext){
    next = newNext;
}

void Node::setPrevious(Node* newPrevious){
    previous = newPrevious;
}

void Node::setData(int newData){
    data = newData;
}
