#pragma once

template <typename T>
class Node{
    public:
        Node(T data, Node<T>* previous = nullptr, Node<T>* next = nullptr)
            : data(data), previousNode(previous), nextNode(next) {}

        // Getters
        Node<T>* getPrevious() const { return previousNode; }
        Node<T>* getNext() const { return nextNode; }
        T getData() const { return data; }

        // Setters
        void setPrevious(Node<T>* newPrevious) { previousNode = newPrevious; }
        void setNext(Node<T>* newNext) { nextNode = newNext; }
        void setData(T newData) { data = newData; }

    private:
        Node<T>* nextNode;
        Node<T>* previousNode;
        T data;
};

