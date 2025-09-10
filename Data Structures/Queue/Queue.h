#pragma once
class Queue{
    public:
        Queue(int initSize = 10);
        ~Queue();

        void enqueue(int data);
        int dequeue();

        void resize(int newSize);

    private:
        int *container;
        int frontPtr;
        int backPtr;
        int currentSize;

        bool isFull();
        bool isEmpty();
};
