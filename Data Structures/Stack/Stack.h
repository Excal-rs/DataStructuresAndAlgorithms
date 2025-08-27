#ifndef STACK_H
#define STACK_H

class Stack {
public:
    Stack(int size = 100);  // Constructor now takes a size argument
    ~Stack();               // Destructor to free dynamically allocated memory

    void push(int number);
    int pop();
    int peak();

private:
    int topPtr;
    int *container;         // Pointer for dynamically allocated array
    int maxSize;            // Max size of the stack
    bool isFull();
    bool isEmpty();
};

#endif
