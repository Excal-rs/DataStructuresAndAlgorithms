#include "Stack.h"
#include <stdexcept>

Stack::Stack(int size) : topPtr(-1), maxSize(size) {
    container = new int[maxSize];  // Dynamically allocate memory for the container
}

Stack::~Stack() {
    delete[] container;  // Free the allocated memory when the stack is destroyed
}

void Stack::push(int number) {
    if (isFull()) {
        throw std::overflow_error("Stack is full");
    }
    container[++topPtr] = number;
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return container[topPtr--];
}

int Stack::peak() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return container[topPtr];
}

bool Stack::isFull() {
    return topPtr >= maxSize - 1;
}

bool Stack::isEmpty() {
    return topPtr == -1;
}
