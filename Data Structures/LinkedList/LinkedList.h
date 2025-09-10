#pragma once

#include "Node.h"
#include <stdexcept>


template <typename T>
class LinkedList{
    public:
        LinkedList() : frontPtr(nullptr), backPtr(nullptr) {}

        // Adding
        void append(T data){
            Node<T>* newNode = new Node<T>(data, backPtr, nullptr);
            if(backPtr) backPtr->setNext(newNode);
            else frontPtr = newNode;
            backPtr = newNode;
        }
        
        void prepend(T data){
            Node<T>* newNode = new Node<T>(data, nullptr, frontPtr);
            if(frontPtr) frontPtr->setPrevious(newNode);
            else backPtr = newNode;
            frontPtr = newNode;
        }

        void insertAt(T data, int index){
            if(index == 0){
                prepend(data);
                return;
            }
            Node<T>* current = frontPtr;
            for(int i = 0; i < index && current; ++i)
                current = current->getNext();
            if(!current){
                append(data);
                return;
            }
            Node<T>* prev = current->getPrevious();
            Node<T>* newNode = new Node<T>(data, prev, current);
            if(prev) prev->setNext(newNode);
            current->setPrevious(newNode);
            if(current == frontPtr) frontPtr = newNode;
        }

        // Removing
        T popFront(){
            if(!frontPtr) throw std::out_of_range("List is empty");
            Node<T>* nodeToDelete = frontPtr;
            T temp = nodeToDelete->getData();
            frontPtr = frontPtr->getNext();
            if(frontPtr) frontPtr->setPrevious(nullptr);
            else backPtr = nullptr;
            delete nodeToDelete;
            return temp;
        }

        T popBack(){
            if(!backPtr) throw std::out_of_range("List is empty");
            Node<T>* nodeToDelete = backPtr;
            T temp = nodeToDelete->getData();
            backPtr = backPtr->getPrevious();
            if(backPtr) backPtr->setNext(nullptr);
            else frontPtr = nullptr;
            delete nodeToDelete;
            return temp;
        }


        void removeAt(int index){
            if(index == 0){
                popFront();
                return;
            }
            Node<T>* current = frontPtr;
            for(int i = 0; i < index && current; ++i)
                current = current->getNext();
            if(!current) return;
            Node<T>* prev = current->getPrevious();
            Node<T>* next = current->getNext();
            if(prev) prev->setNext(next);
            if(next) next->setPrevious(prev);
            if(current == backPtr) backPtr = prev;
            delete current;
        }

        void removeAll(T data){
            Node<T>* current = frontPtr;
            while(current){
                Node<T>* next = current->getNext();

                if(current->getData() == data){
                    if(current == frontPtr) frontPtr = next;
                    if(current == backPtr) backPtr = current->getPrevious();
                    if(current->getPrevious()) current->getPrevious()->setNext(next);
                    if(next) next->setPrevious(current->getPrevious());
                    delete current;
                }
                current = next;
            }
        }

        void removeFirstN(T data, int n){
            Node<T>* current = frontPtr;
            int count = 0;
            while(current && count < n){
                Node<T>* next = current->getNext();
                if(current->getData() == data){
                    if(current == frontPtr) frontPtr = next;
                    if(current == backPtr) backPtr = current->getPrevious();
                    if(current->getPrevious()) current->getPrevious()->setNext(next);
                    if(next) next->setPrevious(current->getPrevious());
                    delete current;
                    count++;
                }
                current = next;
            }
        }

        void removeFirst(T data){
            removeFirstN(data, 1);
        }

        // Getters
        Node<T>* getFront() const { return frontPtr; }
        Node<T>* getBack() const { return backPtr; }
        Node<T>* getAt(int index) const {
            Node<T>* current = frontPtr;
            for(int i = 0; i < index && current; ++i)
                current = current->getNext();
            return current;
        }
        
    private:
        Node<T>* frontPtr;
        Node<T>* backPtr;
};