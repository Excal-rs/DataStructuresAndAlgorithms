#ifndef NODE_H
#define NODE_H

class Node
{
private:
    Node* next;
    Node* previous;
    int data;
public:
    Node(int data, Node* previous = nullptr, Node* next = nullptr);

    Node* getNext();
    Node* getPrevious();
    int getData();

    void setNext(Node* newNext);
    void setPrevious(Node* newPrevious);
    void setData(int newData);
};


#endif 