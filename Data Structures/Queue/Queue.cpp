#include "Queue.h"
#include <stdexcept>

// Constructor / Destructor ----------------------------
Queue::Queue(int initSize) : frontPtr(-1), backPtr(-1), currentSize(initSize) {
    container = new int[currentSize];
}

Queue::~Queue(){
    delete[] container;
}

// Helper methods --------------------------------------
bool Queue::isEmpty(){
    return (frontPtr == -1);
}

bool Queue::isFull(){
    return (backPtr + 1) % currentSize == frontPtr && frontPtr != -1;
}


// Public methods --------------------------------------
void Queue::resize(int newSize) {
    int occupied = (backPtr - frontPtr + currentSize) % currentSize + 1;
    if (isEmpty()) occupied = 0;

    if (newSize < occupied) {
        throw std::invalid_argument("new size must be >= number of elements in queue");
    }

    int* temp = new int[occupied];
    int tempPtr = frontPtr;
    for (int i = 0; i < occupied; i++) {
        temp[i] = container[tempPtr];
        tempPtr = (tempPtr + 1) % currentSize; 
    }

    delete[] container;
    container = new int[newSize];
    currentSize = newSize;

    for (int i = 0; i < occupied; i++) {
        container[i] = temp[i];
    }

    frontPtr = occupied == 0 ? -1 : 0;
    backPtr = occupied == 0 ? -1 : occupied - 1;

    delete[] temp;
}

int Queue::dequeue(){
    if (isEmpty()){
        throw std::underflow_error("Queue is empty");
    }

    int temp = frontPtr;
    if (frontPtr == backPtr){
        frontPtr = -1;
        backPtr = -1;
    } else {
        frontPtr = (frontPtr + 1) % currentSize;
    }
    return container[temp];
}

void Queue::enqueue(int data){
    if (isFull()){
        throw std::overflow_error("Queue is full");
    }
    if (isEmpty()){
        frontPtr = backPtr = 0;
    } else {
        backPtr = (backPtr + 1) % currentSize;
    }
    container[backPtr] = data;
}
