#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        
        void insert(int data, int index);
        void append(int data);
        void prepend(int data);

        Node* get(int index);
        int find(int NodeData);

        void remove(int data);
        void remove_at(int index);
        int pop_back();
        int pop_front();

        int getSize();
        
        void clear();
    
    private:
        int size;
        Node frontPtr;
        Node backPtr;
};

#endif